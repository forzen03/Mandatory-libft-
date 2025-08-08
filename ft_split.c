/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaradat <njaradat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:56:18 by njaradat          #+#    #+#             */
/*   Updated: 2025/08/07 22:17:10 by njaradat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char const *s, char c)
{
	int		flag;
	int		count;
	size_t	i;

	flag = 1;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		if (s[i] == c && flag == 0)
			flag = 1;
		i++;
	}
	return (count);
}

static size_t	size_word(char const *s, char c, size_t start)
{
	size_t	i;
	size_t	j;

	j = start;
	if (s[j] == c)
		j++;
	i = 0;
	while (s[j] && s[j] != c)
	{
		i++;
		j++;
	}
	return (i);
}

static char	*create_word(char const *s, char c, size_t *start)
{
	char	*word;
	size_t	len;

	if (s[*start] == c)
		(*start)++;
	len = size_word(s, c, *start);
	word = ft_substr(s, *start, len);
	while (s[*start] && s[*start] != c)
		(*start)++;
	return (word);
}

static void	free_all(char **s, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	start;
	int		words;
	int		i;
	char	*word;

	words = words_count(s, c);
	start = 0;
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		word = create_word(s, c, &start);
		if (word == NULL)
		{
			free_all(arr, words);
			return (NULL);
		}
		arr[i++] = word;
	}
	arr[i] = NULL;
	return (arr);
}
