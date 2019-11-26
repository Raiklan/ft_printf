/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:03:30 by wpark             #+#    #+#             */
/*   Updated: 2019/11/26 17:24:30 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_normal(char c, int *cnt)
{
	write(1, &c, 1);
	*cnt = *cnt + 1;
}

static int	print(char *f, va_list *ap)
{
	int		i;
	int		cnt;
	t_tab	tab;

	i = 0;
	cnt = 0;
	while (f[i] != '\0')
	{
		if (f[i] == '%')
		{
			f = f + make_tab(&tab, f + i + 1, ap);
			cnt = cnt + print_and_count(tab, ap);
		}
		else
			print_normal(f[i], &cnt);
		i++;
	}
	return (cnt);
}

int			ft_printf(const char *form, ...)
{
	char	*f;
	int		cnt;
	va_list	ap;

	f = (char*)form;
	if (!check_form(f))
		return (0);
	va_start(ap, form);
	cnt = print(f, &ap);
	va_end(ap);
	return (cnt);
}
