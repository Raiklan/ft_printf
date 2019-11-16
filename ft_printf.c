/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:45:12 by saich             #+#    #+#             */
/*   Updated: 2019/11/16 18:50:19 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_normal(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

static int	print(char *format, va_list *ap)
{
	int		i;
	int		count;
	t_tab	tab;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			format = format + make_tab(&tab, format + i + 1, ap);
			count = count + print_and_count(tab, ap);
		}
		else
			print_normal(format[i], &count);
		i++;
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	char	*form;
	int		count;
	va_list	ap;

	form = (char*)format;
	if (!check_form(form))
		return (0);
	va_start(ap, format);
	count = print(form, &ap);
	va_end(ap);
	return (count);
}
