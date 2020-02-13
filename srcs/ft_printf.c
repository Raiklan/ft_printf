/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:03:30 by wpark             #+#    #+#             */
/*   Updated: 2019/11/26 18:13:24 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_normal(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

static int	print(char *f, va_list *ap)
{
	int		i;
	int		count;
	t_tab	tab;

	i = 0;
	count = 0;
	while (f[i] != '\0')
	{
		if (f[i] == '%')
		{
			f = f + make_tab(&tab, f + i + 1, ap);
			count = count + print_and_count(tab, ap);
		}
		else
			print_normal(f[i], &count);
		i++;
	}
	return (count);
}

int			ft_printf(const char *form, ...)
{
	char	*f;
	int		count;
	va_list	ap;

	f = (char*)form;
	if (!check_form(f))
		return (-1);
	va_start(ap, form);
	count = print(f, &ap);
	va_end(ap);
	return (count);
}
