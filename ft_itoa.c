/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaradat <njaradat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 22:08:29 by njaradat          #+#    #+#             */
/*   Updated: 2025/08/07 22:20:27 by njaradat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_of_digit(int n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	digits;
	size_t	i;

	digits = number_of_digit(n);
	if (n <= 0)
		digits++;
	p = (char *)malloc(sizeof(char) * (digits + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	if (digits > number_of_digit(n))
		p[i++] = '-';
	while (digits > 0)
	{
		p[i++] = (n % 10);
		n /= 10;
		digits--;
	}
	p[i] = '\0';
	return (p);
}
