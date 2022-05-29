/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:47:09 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/02/09 11:31:19 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_minus(char *str, t_list *list, int i, int s)
{
	if (list->num_m)
		ft_putchar('-', list);
	while (i < set_precision(str, list, s))
	{
		ft_putchar(str[i], list);
		i++;
		s = 1;
	}
	s = 2;
	list->width -= set_precision(str, list, s);
	while (list->width > 0)
	{
		ft_putchar(' ', list);
		list->width--;
	}
}

void	ft_putstr_zero(char *str, t_list *list, int s)
{
	s = 3;
	if (list->num_m && list->flag_zero && list->precision <= -1)
		ft_putchar('-', list);
	list->width -= set_precision(str, list, s);
	while (list->width > 0)
	{
		if (list->flag_zero && list->precision <= -1)
			ft_putchar('0', list);
		else
			ft_putchar(' ', list);
		list->width--;
	}
	if (list->type == 'p')
	{
		ft_putchar('0', list);
		ft_putchar('x', list);
	}
	if (list->num_m && list->flag_zero && list->precision > -1)
		ft_putchar('-', list);
	if (list->num_m && !list->flag_zero)
		ft_putchar('-', list);
}

void	ft_putstr(char *str, t_list *list)
{
	int i;
	int s;

	if (!str)
		str = "(null)";
	i = 0;
	if (list->flag_minus == 1)
	{
		s = 0;
		ft_putstr_minus(str, list, i, s);
	}
	else
	{
		ft_putstr_zero(str, list, i);
		s = 0;
		while (i < set_precision(str, list, s))
		{
			ft_putchar(str[i], list);
			i++;
			s = 1;
		}
	}
}
