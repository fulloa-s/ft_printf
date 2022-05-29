/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:38:05 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/02/09 11:09:10 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_list *list)
{
	write(1, &c, 1);
	list->count++;
}

void	ft_putchar_mod2(t_list *list)
{
	list->width--;
	while (list->width > 0)
	{
		ft_putchar(' ', list);
		list->width--;
	}
}

void	ft_putchar_mod(char c, t_list *list)
{
	if (list->flag_minus == 1)
	{
		ft_putchar(c, list);
		list->width--;
		while (list->width > 0)
		{
			ft_putchar(' ', list);
			list->width--;
		}
		return ;
	}
	else if (list->flag_zero == 1)
	{
		list->width--;
		while (list->width > 0)
		{
			ft_putchar('0', list);
			list->width--;
		}
	}
	else
	{
		ft_putchar_mod2(list);
	}
	ft_putchar(c, list);
}
