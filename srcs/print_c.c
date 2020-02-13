/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:27:31 by wpark             #+#    #+#             */
/*   Updated: 2020/02/11 17:31:06 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(t_tab tab, va_list *ap)
{
	char	*ret;
	char	c;

	c = va_arg(*ap, int);
	if (!tab.min_w)
		tab.min_w = 1;
	if (tab.zero)
	{
		if (!(ret = zero_malloc(tab.min_w)))
			return (0);
	}
	else if (!(ret = sp_malloc(tab.min_w)))
		return (0);
	if (tab.minus)
		ret[0] = c;
	else
		ret[tab.min_w - 1] = c;
	write(1, ret, tab.min_w);
	free_all(ret);
	return (tab.min_w);
}
