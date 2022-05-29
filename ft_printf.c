/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:58:32 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/02/09 15:14:57 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_type(const char *input, va_list args, int i, t_list *list)
{
	if ((input[i] == 'd' || input[i] == 'i'))
		ft_decimal(args, list);
	else if (input[i] == 'u')
		ft_unsigned(args, list);
	else if (input[i] == 'x' || input[i] == 'X')
	{
		if (input[i] == 'X')
			list->type = 'X';
		ft_hexadecimal(args, list);
	}
	else if (input[i] == 'p')
		ft_address(args, list);
	else if (input[i] == 'c')
		ft_putchar_mod(va_arg(args, int), list);
	else if (input[i] == '%')
		ft_putchar_mod('%', list);
	else if (input[i] == 's')
		ft_putstr(va_arg(args, char *), list);
}

int			ft_print2(const char *input, va_list args, int i, t_list *list)
{
	while (input[i])
	{
		ft_listinit(list);
		if (input[i] == '%' && input[i + 1])
		{
			i++;
			i = ft_checkflag(input, i, list, args);
			ft_print_type(input, args, i, list);
			if (input[i] != 'd' && input[i] != 'i' && input[i] != 'u'
				&& input[i] != 'x' && input[i] != 'X' && input[i] != 'p'
				&& input[i] != 'c' && input[i] != 's' && input[i] != '%')
				break ;
		}
		else
			ft_putchar(input[i], list);
		i++;
	}
	return (i);
}

int			ft_print(const char *input, va_list args)
{
	int			i;
	t_list		*list;
	int			ret;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	list->count = 0;
	i = 0;
	i = ft_print2(input, args, i, list);
	ret = list->count;
	free(list);
	return (ret);
}

void		ft_listinit(t_list *list)
{
	list->flag_minus = 0;
	list->flag_zero = 0;
	list->width = 0;
	list->dot = 0;
	list->precision = -1;
	list->num_0 = 0;
	list->num_m = 0;
	list->type = '0';
}

int			ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;

	va_start(args, input);
	i = ft_print(input, args);
	va_end(args);
	return (i);
}
