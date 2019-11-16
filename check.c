/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:20:48 by saich             #+#    #+#             */
/*   Updated: 2019/11/15 19:31:48 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_minus(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int			check_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

int			check_form(char *format)
{
	int	count;
	int check;

	count = 0;
	check = 0;
	if (!format)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%' && check == 0)
			check = 1;
		else if (check_conversion(*format) && check == 1)
		{
			check = 0;
			count++;
		}
		format++;
	}
	if (check == 1)
		return (0);
	return (1);
}
