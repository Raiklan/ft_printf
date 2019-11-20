/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:51:17 by saich             #+#    #+#             */
/*   Updated: 2019/11/20 16:19:43 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_size(t_tab tab, int *tab_len, int len, char *out)
{
	if (tab.precise == 0 && *out == '0')
		*tab_len = 0;
	else
		*tab_len = (len > tab.precise) ? len : tab.precise;
	return ((*tab_len > tab.min_w) ? *tab_len : tab.min_w);
}

static int	print_without_fminus(char *out, t_tab tab)
{
	int len;
	int tab_len;
	int size;
	int i;

	len = ft_strlen(out);
	size = set_size(tab, &tab_len, len, out);
	i = size - tab_len;
	while (i-- > 0)
	{
		if (tab.precise != -1)
			write(1, " ", 1);
		else if (tab.zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	i = tab_len - len;
	while (i-- > 0)
		write(1, "0", 1);
	if (tab_len != 0 || *out != '0')
		write(1, out, len);
	free_all(out);
	return (size);
}

static int	print_with_fminus(char *out, t_tab tab)
{
	int len;
	int tab_len;
	int size;
	int i;

	len = ft_strlen(out);
	size = set_size(tab, &tab_len, len, out);
	i = tab_len - len;
	while (i-- > 0)
		write(1, "0", 1);
	if (tab_len != 0 || *out != '0')
		write(1, out, len);
	i = size - tab_len;
	while (i-- > 0)
		write(1, " ", 1);
	free_all(out);
	return (size);
}

static int	print_res(char *out, t_tab tab)
{
	if (tab.minus)
		return (print_with_fminus(out, tab));
	else
		return (print_without_fminus(out, tab));
}

int			print_x(t_tab tab, va_list *ap)
{
	char			*out;
	unsigned int	u;

	u = va_arg(*ap, unsigned int);
	if (tab.convert == 'x')
	{
		if (!(out = ft_utoa_base(u, "0123456789abcdef")))
			return (0);
		return (print_res(out, tab));
	}
	else
	{
		if (!(out = ft_utoa_base(u, "0123456789ABCDEF")))
			return (0);
		return (print_res(out, tab));
	}
}
