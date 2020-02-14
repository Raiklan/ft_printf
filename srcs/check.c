/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:20:51 by wpark             #+#    #+#             */
/*   Updated: 2020/02/14 15:17:21 by saich            ###   ########.fr       */
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

int			check_form(char *f)
{
	int check;
	int check_inv;

	check = 0;
	if (!f)
		return (0);
	while (*f != '\0')
	{
		if (*f == '%' && check == 0)
			check = 1;
		else if (check_conversion(*f) && check == 1)
			check = 0;
		else if (!ft_isdigit(*f) && !check_conversion(*f) && *f != '-' 
		&& *f != '*' && *f != '.')
			check_inv = 1;
		f++;
	}
	if (check == 1 || check_inv == 1)
		return (0);
	return (1);
}
