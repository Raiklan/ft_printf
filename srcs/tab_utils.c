/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:18:17 by wpark             #+#    #+#             */
/*   Updated: 2020/02/14 22:44:44 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_tab(t_tab *tab)
{
	tab->minus = 0;
	tab->zero = 0;
	tab->min_w = 0;
	tab->precise = -1;
	tab->convert = 0;
}

static void	get_zero_minus(t_tab *tab, char **form, int *digit)
{
	*digit = 0;
	while (**form == '-' || **form == '0' || **form == ' ')
	{
		if (**form == '-')
			tab->minus = 1;
		else if (**form == '0')
			tab->zero = 1;
		(*form)++;
	}
}

static void	get_min_w(t_tab *tab, char **form, va_list *ap)
{
	int	digit;

	get_zero_minus(tab, form, &digit);
	while (**form != '.' && !check_conversion(**form))
	{
		if (ft_isdigit(**form))
			digit = (digit * 10) + (**form - '0');
		else if (**form == '*')
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
		(*form)++;
	}
	tab->min_w = (digit) ? digit : tab->min_w;
}

static void	get_precision(t_tab *tab, char **form, va_list *ap)
{
	int digit;

	digit = 0;
	while (!check_conversion(**form))
	{
		if (ft_isdigit(**form))
			digit = (digit * 10) + (**form - '0');
		else if (**form == '*')
		{
			if ((tab->precise = va_arg(*ap, int)) < 0)
				tab->precise = -1;
			digit = tab->precise;
		}
		(*form)++;
	}
	tab->precise = digit;
}

int			make_tab(t_tab *tab, char *form, va_list *ap)
{
	char	*begin;

	begin = form;
	init_tab(tab);
	get_min_w(tab, &form, ap);
	if (*form == '.')
		get_precision(tab, &form, ap);
	tab->convert = *form++;
	return (form - begin);
}
