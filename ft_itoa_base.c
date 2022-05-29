/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:15:27 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/02/09 10:49:02 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size_number_uns_diffbase(size_t n, char *base)
{
	int i;
	int x;

	x = ft_strlen(base);
	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / x;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(size_t n, char *base)
{
	char	*str;
	int		len;
	int		size_base;
	int		save;

	size_base = ft_strlen(base);
	len = ft_size_number_uns_diffbase(n, base);
	save = len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	while (len-- > 0)
	{
		str[len] = base[(n % size_base)];
		n = n / size_base;
	}
	str[save] = '\0';
	return (str);
}
