/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:32:23 by saich             #+#    #+#             */
/*   Updated: 2019/11/16 19:56:14 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_sp(t_tab tab, int sign, char **out, int i)
{
	if (tab.zero == 1 && tab.precise == -1)
	{
		if (sign && (*out)++)
			write(1, "-", 1);
		while (i--)
			write(1, "0", 1);
	}
	else
	{
		while (i--)
			write(1, " ", 1);
		if (sign && (*out)++)
			write(1, "-", 1);
	}
}

static int		print_d_with_minus(char *out, t_tab tab, int sign)
{
	int		len;
	int		tab_len;
	int		size;
	int		i;
	char	*begin;

	begin = out;
	len = ft_strlen(out) - sign;
	if (tab.precise == 0 && *out == '0')
		tab_len = 0;
	else
		tab_len = (len > tab.precise) ? len : tab.precise;
	size = ((tab_len + sign > tab.min_w) ? tab_len + sign : tab.min_w);
	if (sign)
		write(1, &*out++, 1);
	i = tab_len - len;
	while (i-- > 0)
		write(1, "0", 1);
	if (tab_len != 0 || *out != '0')
		write(1, out, len);
	i = size - tab_len - sign;
	while (i-- > 0)
		write(1, " ", 1);
	free_all(begin);
	return (size);
}

static int		print_d_whithout_minus(char *out, t_tab tab, int sign)
{
	char		*begin;
	int			len;
	int			size;
	int			tab_len;
	int			i;

	begin = out;
	len = ft_strlen(out) - sign;
	if (tab.precise == 0 && *out == '0')
		tab_len = 0;
	else
		tab_len = (len > tab.precise) ? len : tab.precise;
	size = ((tab_len + sign > tab.min_w) ? tab_len + sign : tab.min_w);
	i = size - tab_len - sign;
	print_sp(tab, sign, &out, i);
	i = tab_len - len;
	while (i-- > 0)
		write(1, "0", 1);
	if (tab_len != 0 || *out != '0')
		write(1, out, len);
	free_all(begin);
	return (size);
}

int				print_d(t_tab tab, va_list ap)
{
	int			digit;
	char		*out;
	int			sign;

	digit = va_arg(ap, int);
	sign = (digit < 0) ? 1 : 0;
	if (!(out = ft_itoa_base(digit, "0123456789")))
		return (0);
	if (tab.minus)
		return (print_d_with_minus(out, tab, sign));
	else
		return (print_d_whithout_minus(out, tab, sign));
}
