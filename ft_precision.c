/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:10:42 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/02/09 11:57:22 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_precision_string(t_list *list, int i)
{
	if (list->dot == 2)
		return (0);
	if (list->precision <= -1)
		return (i);
	if (list->precision < i)
		return (list->precision);
	else
		return (i);
}

int		set_precision(char *str, t_list *list, int s)
{
	int i;

	i = ft_strlen(str);
	if (list->type == '0')
		return (set_precision_string(list, i));
	else
	{
		if (list->precision == -1 || list->precision <= i)
		{
			if (list->num_0 == 1 && list->precision == 0)
				i--;
			if (list->num_0 == 1 && list->dot == 2)
				i--;
			return (i);
		}
		if (list->precision > i && (s == 0 || s == 2 || s == 3))
			return (ft_printzero(list, i, s));
		else
			return (i);
	}
}

int		ft_printzero(t_list *list, int i, int s)
{
	int x;

	x = list->precision - i;
	if (s == 0)
	{
		while (x)
		{
			ft_putchar('0', list);
			x--;
		}
		return (i);
	}
	if (s == 3)
	{
		return (list->precision);
	}
	else
		return (x + i);
}
