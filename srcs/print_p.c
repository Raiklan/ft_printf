/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:52:31 by wpark             #+#    #+#             */
/*   Updated: 2020/02/14 14:26:08 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_ptr(char *ptr, t_tab tab)
{
	int i;

	i = tab.precise;
	if (tab.precise != 0 || *ptr != '0')
		write(1, ptr, ft_strlen(ptr));
	i -= ft_strlen(ptr);
	while(i-- > 0)
		write(1, "0", 1);
}

static void	print_res_with_minus(char *ptr, t_tab tab, int sp)
{
	write(1, "0x", 2);
	print_ptr(ptr, tab);
	while (sp-- > 0)
	{
		if (tab.zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
}

static void	print_res_without_minus(char *ptr, t_tab tab, int sp)
{
	if (tab.zero)
	{
		write(1, "0x", 2);
		while (sp-- > 0)
			write(1, "0", 1);
	}
	else
	{
		while (sp-- > 0)
			write(1, " ", 1);
		write(1, "0x", 2);
	}
	print_ptr(ptr, tab);
}

static void	print_res(char *ptr, t_tab tab, int sp)
{
	if (tab.minus)
		print_res_with_minus(ptr, tab, sp);
	else
		print_res_without_minus(ptr, tab, sp);
}

int			print_p(t_tab tab, va_list *ap)
{
	long	n;
	char	*ret;
	int		size;
	int		len;
	int		p_len;

	n = (unsigned long)va_arg(*ap, void*);
	if (!(ret = ft_itoa_base(n, "0123456789abcdef", 16)))
		return (0);
	if (tab.precise == 0 && *ret == '0')
		p_len = 0 + 2;
	else
	{
		len = ft_strlen(ret) + 2;
		p_len = (len > tab.precise + 2) ? len : tab.precise + 2;
	}
	size = (p_len > tab.min_w) ? p_len : tab.min_w;
	print_res(ret, tab, size - p_len);
	free_all(ret);
	return (size);
}
