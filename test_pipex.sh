# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_pipex.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwittwer <lwittwer@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 17:27:47 by lwittwer          #+#    #+#              #
#    Updated: 2025/10/18 23:57:00 by lwittwer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# ===========================
# Pipex Testing Script
# ===========================
# Compares your program's output and exit code
# to what the shell does with: < infile cmd1 | cmd2 > outfile
# ===========================

# -- Color setup for nice output --
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# -- Path to your program --
PIPEX=./pipex

# -- Temporary working directory --
TMPDIR=tmp_test_dir
mkdir -p "$TMPDIR"

# ===========================
# Test Function
# ===========================
run_test() {
    local desc="$1"       # Description of the test
    local infile="$2"     # Input file path
    local cmd1="$3"       # First command (quoted)
    local cmd2="$4"       # Second command (quoted)
    local expected_code="$5"  # Expected exit code from pipex
	local use_env_i="${6:-false}"

    local outfile_pipex="$TMPDIR/outfile_pipex"
    local outfile_shell="$TMPDIR/outfile_shell"

    echo "== $desc =="

	# -- Run pipex --
    if [ "$use_env_i" = true ]; then
        env -i $PIPEX "$infile" "$cmd1" "$cmd2" "$outfile_pipex"
    else
        $PIPEX "$infile" "$cmd1" "$cmd2" "$outfile_pipex"
    fi
    local exit_code=$?

    # -- Run equivalent shell pipeline --
    if [ "$use_env_i" = true ]; then
        env -i PATH=  /usr/bin/bash --posix --norc --noprofile -c "< $infile $cmd1 | $cmd2 > $outfile_shell"
    else
        bash --posix -c "< $infile $cmd1 | $cmd2 > $outfile_shell"
    fi

    # -- Compare output files --
    if diff -q "$outfile_pipex" "$outfile_shell" > /dev/null; then
        output_result="${GREEN}[MATCH]${NC}"
    else
        output_result="${RED}[DIFF]${NC}"
        echo -e "${RED}  ↳ Output differs. Run diff to investigate.${NC}"
    fi

    # -- Compare exit code --
    if [ "$exit_code" -eq "$expected_code" ]; then
        code_result="${GREEN}[PASS]${NC}"
    else
        code_result="${RED}[FAIL]${NC} (got $exit_code, expected $expected_code)"
    fi

    # -- Print results --
    echo -e "Exit code: $code_result"
    echo -e "Output:    $output_result"
    echo
}

# ===========================
# Example Test
# ===========================

# Example:
# run_test "Your test description" "$TMPDIR/your_input" "your_cmd1" "your_cmd2" expected_exit_code

# ===========================
# Add your tests below
# ===========================

# Prepare an input file
echo "Chocobos rule 42Vienna!" > "$TMPDIR/infile"

run_test "Test 1 command not found(relative)" "$TMPDIR/infile" "cat" "greep" 127
run_test "Test 2 with empty env -i" "$TMPDIR/infile" "cat" "wc" 127 true
run_test "Test 3 command not found(absolut)" "$TMPDIR/infile" "cat" "/bin/doesnotexist" 127
run_test "Test 4 is a directory (EISDIR)" "$TMPDIR/infile" "cat" "/bin" 126
printf "dummy" > tmp_test_dir/nodir
run_test "Test 5 not a directory (ENOTDIR)" "$TMPDIR/infile" "cat" "$TMPDIR/nodir" 126
printf '#!/bin/sh\necho HI\n' > tmp_test_dir/myscript
chmod 644 tmp_test_dir/myscript
run_test "Test 6 permission denied no execute right" "$TMPDIR/infile" "cat" "tmp_test_dir/myscript" 126
touch tmp_test_dir/empty
chmod 755 tmp_test_dir/empty
run_test "Test 7 exec format error (ENOEXEC)" "$TMPDIR/infile" "cat" "tmp_test_dir/empty" 0
run_test "Test 8 command gives error != 0)" "$TMPDIR/infile" "cat" "grep ZZZ" 1
yes "abc" | head -n 50000 > "$TMPDIR/infile"
run_test "Test 9 big input" "$TMPDIR/infile" "grep abc" "wc -l" 0

# ===========================
# Cleanup
# ===========================
# Uncomment this to automatically delete files after testing
rm -rf "$TMPDIR"

