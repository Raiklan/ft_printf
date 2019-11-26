/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:52:31 by wpark             #+#    #+#             */
/*   Updated: 2019/11/26 17:26:12 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_ptr(char *ptr, t_tab tab)
{
	write(1, "0x", 2);
	if (tab.precise != 0 || *ptr != '0')
		write(1, ptr, ft_strlen(ptr));
}

static void	print_res(char *ptr, t_tab tab, int sp)
{
	if (tab.minus)
	{
		print_ptr(ptr, tab);
		while (sp-- > 0)
			write(1, " ", 1);
	}
	else
	{
		while (sp-- > 0)
			write(1, " ", 1);
		print_ptr(ptr, tab);
	}
}

int			print_p(t_tab tab, va_list *ap)
{
	long	n;
	char	*ret;
	int		size;
	int		len;

	n = (unsigned long)va_arg(*ap, void*);
	if (!(ret = ft_itoa_base(n, "0123456789abcdef", 16)))
		return (0);
	if (tab.precise == 0 && *ret == '0')
		len = 0 + 2;
	else
		len = ft_strlen(ret) + 2;
	size = (len > tab.min_w) ? len : tab.min_w;
	print_res(ret, tab, size - len);
	free_all(ret);
	return (size);
}
