/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:20:51 by saich             #+#    #+#             */
/*   Updated: 2020/04/17 20:42:46 by saich            ###   ########.fr       */
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
	int	i;

	check = 0;
	i = 0;
	check_inv = 0;
	if (!f)
		return (0);
	while (f[i] != '\0')
	{
		if (f[i] == '%' && check == 0)
		{
			check = 1;
			if (f[i + 1] != '\0' && !ft_isdigit(f[i + 1]) 
			&& !check_conversion(f[i + 1]) && f[i + 1] != '-' 
			&& f[i + 1] != '*' && f[i + 1] != '.')
				check_inv = 1;
		}
		else if (check_conversion(f[i]) && check == 1)
			check = 0;
		i++;
	}
	if (check == 1 || check_inv == 1)
		return (0);
	return (1);
}
