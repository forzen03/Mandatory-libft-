/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaradat <njaradat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:11:46 by njaradat          #+#    #+#             */
/*   Updated: 2025/08/07 22:20:16 by njaradat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_start_index(char const *s1, char const *set, int *len)
{
	size_t	i;

	i = 0;
	while (is_in_set(s1[i], set))
	{
		i++;
		(*len)++;
	}
	return (i);
}

static size_t	get_end_index(char const *s1, char const *set, int *len)
{
	size_t	end;

	end = ft_strlen(s1) - 1;
	while (is_in_set(s1[end], set))
	{
		end--;
		(*len)++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	size_t	start;
	size_t	end;
	char	*p;
	size_t	i;

	if (set == NULL)
		return (ft_strdup(s1));
	if (s1 == NULL)
		return (NULL);
	i = 0;
	len = 0;
	start = get_start_index(s1, set, &len);
	end = get_end_index(s1, set, &len);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);
	while (start <= end)
		p[i++] = s1[start++];
	p[i] = '\0';
	return (p);
}
