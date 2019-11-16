/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:51:23 by saich             #+#    #+#             */
/*   Updated: 2019/11/16 19:12:21 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*copy_to_out(int size, int len, t_tab tab, char *str)
{
	char	*out;
	int		i;
	int		space;

	if(!(out = sp_malloc(size)))
		return (0);
	i = 0;
	if (tab.minus)
		while (len--)
			out[i++] = *str++;
	else
	{
		space = size - len;
		while (space--)
		{
			if (tab.zero)
				out[i] = 0;
			i++;
		}
		while (len--)
			out[i++] = *str++;
	}
	return (out);
}

int		print_s(t_tab tab, va_list ap)
{
	char	*out;
	char	*str;
	int		len;
	int		size;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	len = (tab.precise != -1 && len > tab.precise) ? tab.precise : len;
	size = (len > tab.min_w) ? len : tab.min_w;
	if (!(out = copy_to_out(size, len, tab, str)))
		return (0);
	write (1, out, size);
	free_all(out);
	return (size);
}
