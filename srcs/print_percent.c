/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:26:02 by wpark             #+#    #+#             */
/*   Updated: 2019/11/26 17:26:34 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_tab tab, va_list *ap)
{
	char	*ret;

	(void)ap;
	if (!tab.min_w)
		tab.min_w = 1;
	if (!(ret = sp_malloc(tab.min_w)))
		return (0);
	if (tab.minus)
		ret[0] = '%';
	else
		ret[tab.min_w - 1] = '%';
	write(1, ret, tab.min_w);
	free_all(ret);
	return (tab.min_w);
}
