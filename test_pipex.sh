#!/bin/bash
# 42 Pipex Tester (Mandatory)
# Author: ChatGPT
# Features:
#  - Output + exit code comparison
#  - Optional Valgrind memory leak check (--valgrind)

PIPEX=./pipex
INFILE=infile.txt
OUT1=out_pipex.txt
OUT2=out_shell.txt
ERR1=err_pipex.txt
ERR2=err_shell.txt

VALGRIND_MODE=false
if [ "$1" == "--valgrind" ]; then
  VALGRIND_MODE=true
fi

# Colors
GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[1;33m"
BLUE="\033[0;34m"
RESET="\033[0m"

# Check binary
if [ ! -x "$PIPEX" ]; then
  echo -e "${RED}Error:${RESET} $PIPEX not found or not executable."
  exit 1
fi

# Check valgrind if requested
if $VALGRIND_MODE && ! command -v valgrind >/dev/null; then
  echo -e "${RED}Error:${RESET} Valgrind not found."
  exit 1
fi

# Create a test infile
echo -e "hello world\nthis is a test\nfoo bar\n42 pipex project" > $INFILE

# Run one test
run_test() {
  local desc="$1"
  local infile="$2"
  local cmd1="$3"
  local cmd2="$4"
  local outfile="$5"

  printf "\n${YELLOW}Test:${RESET} %s\n" "$desc"

  # Pipex run
  if $VALGRIND_MODE; then
    valgrind --quiet --leak-check=full --error-exitcode=42 \
      --log-file=valgrind.log \
      $PIPEX "$infile" "$cmd1" "$cmd2" "$outfile.pipex" 2> "$ERR1"
    EXIT1=$?
  else
    $PIPEX "$infile" "$cmd1" "$cmd2" "$outfile.pipex" 2> "$ERR1"
    EXIT1=$?
  fi

  # Shell equivalent
  bash -c "< $infile $cmd1 | $cmd2 > $outfile.shell" 2> "$ERR2"
  EXIT2=$?

  # Compare outputs
  diff "$outfile.pipex" "$outfile.shell" > /dev/null
  OUT_DIFF=$?
  diff "$ERR1" "$ERR2" > /dev/null
  ERR_DIFF=$?

  local result_msg=""
  local color=$RED

  if [ $OUT_DIFF -eq 0 ] && [ $EXIT1 -eq $EXIT2 ]; then
    if $VALGRIND_MODE; then
      if [ $EXIT1 -eq 42 ]; then
        result_msg="❌ Memory leaks or invalid reads detected"
      elif grep -q "definitely lost: 0 bytes" valgrind.log && \
           grep -q "indirectly lost: 0 bytes" valgrind.log && \
           grep -q "Invalid read" valgrind.log == false; then
        result_msg="✅ OK (exit=$EXIT1, no leaks)"
        color=$GREEN
      else
        result_msg="⚠️ Check Valgrind log (possible leaks)"
      fi
    else
      result_msg="✅ OK (exit=$EXIT1)"
      color=$GREEN
    fi
  else
    result_msg="❌ FAIL"
  fi

  echo -e "${color}${result_msg}${RESET}"
  if [ $OUT_DIFF -ne 0 ]; then
    echo "  ↳ Output differs"
  fi
  if [ $EXIT1 -ne $EXIT2 ]; then
    echo "  ↳ Exit code: pipex=$EXIT1 | shell=$EXIT2"
  fi
  if [ $ERR_DIFF -ne 0 ]; then
    echo "  ↳ Stderr differs"
  fi

  rm -f valgrind.log
}

# --- TESTS ---

run_test "basic grep | wc" "$INFILE" "grep test" "wc -l" "out1"
run_test "cat | wc" "$INFILE" "cat" "wc -c" "out2"
run_test "grep nomatch | wc" "$INFILE" "grep nomatch" "wc -l" "out3"
run_test "head -n 2 | tail -n 1" "$INFILE" "head -n 2" "tail -n 1" "out4"
run_test "invalid first cmd" "$INFILE" "no_such_command" "wc -l" "out5"
run_test "invalid second cmd" "$INFILE" "cat" "notrealcmd" "out6"
run_test "empty infile" "/dev/null" "cat" "wc -l" "out7"
run_test "absolute paths" "$INFILE" "/bin/cat" "/usr/bin/wc -l" "out8"

# Final message
echo -e "\n${BLUE}All tests completed.${RESET}"
$VALGRIND_MODE && echo -e "${YELLOW}Valgrind mode was enabled.${RESET}"
