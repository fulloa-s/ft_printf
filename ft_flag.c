/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:09:14 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/02/09 14:00:33 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkflagfin(t_list *list, int i)
{
	if (list->flag_zero == 1 && list->flag_minus == 1)
		list->flag_zero = 0;
	if (list->width < 0)
	{
		list->flag_minus = 1;
		list->width *= -1;
	}
	return (i);
}

int		ft_checkflag1(const char *input, int i, t_list *list, va_list args)
{
	if (input[i] == '-')
		list->flag_minus = 1;
	else if (input[i] == '0')
		list->flag_zero = 1;
	else if (input[i] > '0' && input[i] <= '9')
	{
		list->width = ft_atoi((char *)input + i);
		while (input[i + 1] >= '0' && input[i + 1] <= '9')
			i++;
	}
	else if (input[i] == '*')
		list->width = va_arg(args, int);
	return (i);
}

int		ft_checkflag(const char *input, int i, t_list *list, va_list args)
{
	while (input[i] == '-' || input[i] == '0' || input[i] == '*' ||
		(input[i] > '0' && input[i] <= '9') || input[i] == '.')
	{
		i = ft_checkflag1(input, i, list, args);
		if (input[i] == '.')
		{
			list->dot = 1;
			i++;
			if (input[i] == '*')
				list->precision = va_arg(args, int);
			else if (input[i] >= '0' && input[i] <= '9')
			{
				list->precision = ft_atoi((char *)input + i);
				while (input[i + 1] >= '0' && input[i + 1] <= '9')
					i++;
			}
			else
			{
				list->dot = 2;
				break ;
			}
		}
		i++;
	}
	return (ft_checkflagfin(list, i));
}
