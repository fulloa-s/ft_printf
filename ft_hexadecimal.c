/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:26:50 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/02/09 11:04:49 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_hexadecimal(va_list args, t_list *list)
{
	char	*str_numb;
	int		x;

	x = va_arg(args, size_t);
	if (x == 0)
		list->num_0 = 1;
	if (list->type == 'X')
		str_numb = ft_itoa_base((unsigned int)x, BASE16);
	else
		str_numb = ft_itoa_base((unsigned int)x, BASE16U);
	list->type = 'd';
	ft_putstr(str_numb, list);
	free(str_numb);
}
