/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:03:30 by saich             #+#    #+#             */
/*   Updated: 2020/04/17 20:47:44 by saich            ###   ########.fr       */
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

static void print_invalidform(char c, int *count)
{
	if (c != '%')
	{
		write(1, &c, 1);
		*count = *count + 1;
	}
}

int			ft_printf(const char *form, ...)
{
	char	*f;
	int		count;
	int		i;
	va_list	ap;

	f = (char*)form;
	if (!check_form(f))
	{
		f = (char*)form;
		count = 0;
		i = 0;
		while (f[i] != '\0')
		{
			print_invalidform(f[i], &count);
			i++;
		}
		return (count);
	}
	va_start(ap, form);
	count = print(f, &ap);
	va_end(ap);
	return (count);
}
