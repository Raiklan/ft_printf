/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:48:38 by saich             #+#    #+#             */
/*   Updated: 2019/11/15 19:46:08 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_pl(t_tab *tab)
{
	tab->minus = 0;
	tab->zero = 0;
	tab->dot = 0;
	tab->min_w = 0;
	tab->precise = -1;
	tab->convert = 0;
}

static void	get_zero_minus(t_tab *tab, char **format, int *digit)
{
	*digit = 0;
	while (*format == '0' || *format == '-' || **format == ' ')
	{
		if (*format == '-')
			tab->minus = 1;
		else if (*format == '0')
			tab->zero = 1;
		(*format)++;
	}
}

static void	get_min_w(t_tab *tab, char **format, va_list *ap)
{
	int digit;

	get_zero_minus(tab, format, &digit);
	while (**format != '.' && !check_conversion(**format))
	{
		if (ft_isdigit(**format))
			digit = digit * 10 + (**format) - '0';
		else if (**format == '*')
		{
			if ((tab->min_w = va_arg(*ap, int)) < 0)
			{
				tab->min_w = -1 * tab->min_w;
				tab->minus = 1;
			}
			digit = 0;
		}
		else
		{
			if (digit)
				tab->min_w = digit;
			digit = 0;
		}
		(*format)++;
	}
	tab->min_w = (digit) ? digit : tab->min_w;
}

static void	get_precision(t_tab *tab, char **format, va_list *ap)
{
	int digit;

	digit = 0;
	while(!(check_conversion(format)))
	{
		if(ft_isdigit(**format))
			digit = digit * 10 + (**format) - '0';
		else if (**format == '*')
		{
			if (tab->precise = va_arg(*ap, int) < 0)
				tab->precise = -1;
			digit = tab->precise;
		}
		(**format)++;
	}
	tab->precise = digit;
}

int			make_tab(t_tab *tab, char *format, va_list *ap)
{
	char	*begin;

	begin = format;
	init_pl(tab);
	get_min_w(tab, &format, ap);
	if (*format == '.')
		get_precision(tab, &format, ap);
	tab->convert = *format++;
	return (format - begin);
}
