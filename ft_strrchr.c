/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaradat <njaradat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:31:16 by njaradat          #+#    #+#             */
/*   Updated: 2025/08/07 22:22:43 by njaradat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	if (s[slen] == c)
		return ((char *)s + slen);
	slen--;
	while (slen >= 0)
	{
		if (s[slen] == c)
			return ((char *)s + slen);
		slen--;
	}
	return (NULL);
}
