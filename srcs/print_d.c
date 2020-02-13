/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:25:29 by wpark             #+#    #+#             */
/*   Updated: 2019/11/29 13:52:13 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_pad(t_tab tab, int sign, char **ret, int i)
{
	if (tab.zero == 1 && tab.precise == -1)
	{
		if (sign && (*ret)++)
			write(1, "-", 1);
		while (i--)
			write(1, "0", 1);
	}
	else
	{
		while (i--)
			write(1, " ", 1);
		if (sign && (*ret)++)
			write(1, "-", 1);
	}
}

static int	print_without_minus(char *ret, t_tab tab, int sign)
{
	int		len;
	int		p_len;
	int		size;
	int		i;
	char	*begin;

	begin = ret;
	len = ft_strlen(ret) - sign;
	if (tab.precise == 0 && *ret == '0')
		p_len = 0;
	else
		p_len = (len > tab.precise) ? len : tab.precise;
	size = ((p_len + sign > tab.min_w) ? p_len + sign : tab.min_w);
	i = size - p_len - sign;
	print_pad(tab, sign, &ret, i);
	i = p_len - len;
	while (i-- > 0)
		write(1, "0", 1);
	if (p_len != 0 || *ret != '0')
		write(1, ret, len);
	free_all(begin);
	return (size);
}

static int	print_with_minus(char *ret, t_tab tab, int sign)
{
	int		len;
	int		p_len;
	int		size;
	int		i;
	char	*begin;

	begin = ret;
	len = ft_strlen(ret) - sign;
	if (tab.precise == 0 && *ret == '0')
		p_len = 0;
	else
		p_len = (len > tab.precise) ? len : tab.precise;
	size = ((p_len + sign > tab.min_w) ? p_len + sign : tab.min_w);
	if (sign)
		write(1, &*ret++, 1);
	i = p_len - len;
	while (i-- > 0)
		write(1, "0", 1);
	if (p_len != 0 || *ret != '0')
		write(1, ret, len);
	i = size - p_len - sign;
	while (i-- > 0)
		write(1, " ", 1);
	free_all(begin);
	return (size);
}

static int	print_res(char *ret, t_tab tab, int sign)
{
	if (tab.minus)
		return (print_with_minus(ret, tab, sign));
	else
		return (print_without_minus(ret, tab, sign));
}

int			print_d(t_tab tab, va_list *ap)
{
	char	*ret;
	int		d;
	int		sign;

	d = va_arg(*ap, int);
	sign = (d < 0) ? 1 : 0;
	if (!(ret = ft_itoa_base(d, "0123456789", 10)))
		return (0);
	return (print_res(ret, tab, sign));
}
