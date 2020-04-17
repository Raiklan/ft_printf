/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:23:35 by saich             #+#    #+#             */
/*   Updated: 2020/04/17 20:47:32 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_size(t_tab tab, int *p_len, int len, char *ret)
{
	if (tab.precise == 0 && *ret == '0')
		*p_len = 0;
	else
		*p_len = (len > tab.precise) ? len : tab.precise;
	return ((*p_len > tab.min_w) ? *p_len : tab.min_w);
}

static int	print_without_minus(char *ret, t_tab tab)
{
	int len;
	int p_len;
	int size;
	int i;

	len = ft_strlen(ret);
	size = set_size(tab, &p_len, len, ret);
	i = size - p_len;
	while (i-- > 0)
	{
		if (tab.precise != -1)
			write(1, " ", 1);
		else if (tab.zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	i = p_len - len;
	while (i-- > 0)
		write(1, "0", 1);
	if (p_len != 0 || *ret != '0')
		write(1, ret, len);
	free_all(ret);
	return (size);
}

static int	print_with_minus(char *ret, t_tab tab)
{
	int len;
	int p_len;
	int size;
	int i;

	len = ft_strlen(ret);
	size = set_size(tab, &p_len, len, ret);
	i = p_len - len;
	while (i-- > 0)
		write(1, "0", 1);
	if (p_len != 0 || *ret != '0')
		write(1, ret, len);
	i = size - p_len;
	while (i-- > 0)
		write(1, " ", 1);
	free_all(ret);
	return (size);
}

static int	print_res(char *ret, t_tab tab)
{
	if (tab.minus)
		return (print_with_minus(ret, tab));
	else
		return (print_without_minus(ret, tab));
}

int			print_u(t_tab tab, va_list *ap)
{
	char			*ret;
	unsigned int	u;

	u = va_arg(*ap, unsigned int);
	if (!(ret = ft_utoa_base(u, "0123456789", 10)))
		return (0);
	return (print_res(ret, tab));
}
