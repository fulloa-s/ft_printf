/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:29:58 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/02/09 10:49:25 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_unsigned(va_list args, t_list *list)
{
	char	*str_numb;
	int		x;

	x = va_arg(args, unsigned int);
	if (x == 0)
		list->num_0 = 1;
	str_numb = ft_itoa_base((unsigned int)x, BASE10);
	list->type = 'd';
	ft_putstr(str_numb, list);
	free(str_numb);
}
