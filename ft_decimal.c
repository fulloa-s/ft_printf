/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:45:35 by fulloa-s          #+#    #+#             */
/*   Updated: 2021/02/09 10:48:05 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_decimal(va_list args, t_list *list)
{
	char	*str_numb;
	int		x;

	x = va_arg(args, int);
	if (x == 0)
		list->num_0 = 1;
	if (x < 0)
		list->num_m = 1;
	if (list->num_m == 1)
	{
		x *= -1;
		list->width--;
	}
	str_numb = ft_itoa(x);
	list->type = 'd';
	ft_putstr(str_numb, list);
	free(str_numb);
}
