/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:20:50 by saich             #+#    #+#             */
/*   Updated: 2019/11/16 18:50:01 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_c(t_tab tab, va_list ap)
{
	char	*out;
	char	c;

	c = va_arg(ap, int);
	if (!tab.min_w)
		tab.min_w = 1;
	if (!(out = sp_malloc(tab.min_w)))
		return (0);
	if (tab.minus)
		out[0] = c;
	else
		out[tab.min_w - 1] = c;
	write(1, out, tab.min_w);
	free_all(out);
	return (tab.min_w);
}
