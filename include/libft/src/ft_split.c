/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:30:28 by texenber          #+#    #+#             */
/*   Updated: 2025/09/12 09:04:25 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	int		trigger;

	count = 0;
	trigger = -1;
	while (*s)
	{
		if (*s != c && trigger < 0)
		{
			count++;
			trigger++;
		}
		else if (*s == c)
			trigger = -1;
		s++;
	}
	return (count);
}

static char	*phil_word(const char *s, ssize_t t_start, size_t i)
{
	char	*str;
	size_t	j;

	j = 0;
	str = ft_calloc((i - t_start + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (t_start < (ssize_t)i)
		str[j++] = s[t_start++];
	str[j] = '\0';
	return (str);
}

static void	f_clean(char **words, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static char	**write_arr(const char *s, char c, char **words)
{
	size_t	i;
	size_t	j;
	ssize_t	t_start;

	i = 0;
	j = 0;
	t_start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && t_start < 0)
			t_start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && t_start >= 0)
		{
			words[j] = phil_word(s, t_start, i);
			if (!(words[j]))
				return (f_clean(words, j), NULL);
			t_start = -1;
			j++;
		}
		i++;
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	int		count;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	words = ft_calloc((count + 1), sizeof(char *));
	if (!words)
		return (NULL);
	words = write_arr(s, c, words);
	if (!words)
		return (NULL);
	return (words);
}
/*
#include <stdio.h>
int main(void)
{
	const char  *s= "hey   how are  you     ";
   	char    c;
    char    **result;
    size_t  i;

    i = 0;
 	c = ' ';
    result = ft_split(s, c);
    if (result)
    {
        while(result[i])
        {
            printf("%s\n", result[i]);
			free(result[i]);
            i++;
        }
        free(result);
    }
    return (0);
}
*/
