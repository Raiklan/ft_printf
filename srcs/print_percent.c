/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:50:59 by saich             #+#    #+#             */
/*   Updated: 2019/11/20 16:37:49 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_percent(t_tab tab, va_list *ap)
{
	char	*out;

	(void)ap;
	if (!tab.min_w)
		tab.min_w = 1;
	if (!(out = sp_malloc(tab.min_w)))
		return (0);
	if (tab.minus)
		out[0] = '%';
	else
		out[tab.min_w - 1] = '%';
	write(1, out, tab.min_w);
	free_all(out);
	return (tab.min_w);
}
