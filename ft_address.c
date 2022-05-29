/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:45:16 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/02/09 10:50:10 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_address(va_list args, t_list *list)
{
	char	*str_numb;
	size_t	x;

	x = va_arg(args, size_t);
	if (x == 0)
		list->num_0 = 1;
	str_numb = ft_itoa_base(x, BASE16U);
	list->type = 'p';
	if (list->flag_minus == 1)
	{
		ft_putchar('0', list);
		ft_putchar('x', list);
	}
	list->width -= 2;
	ft_putstr(str_numb, list);
	free(str_numb);
}
