/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_count_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:08:39 by saich             #+#    #+#             */
/*   Updated: 2019/11/15 19:09:11 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_all(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = 0;
}

char	*sp_malloc(int size)
{
	char	*ret;
	int		i;

	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (size--)
		ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}

int		print_and_count(t_tab tab, va_list *ap)
{
	if (tab.convert == 'c')
		return (print_c(tab, ap));
	if (tab.convert == 's')
		return (print_s(tab, ap));
	if (tab.convert == 'p')
		return (print_p(tab, ap));
	if (tab.convert == 'd' || tab.convert == 'i')
		return (print_d(tab, ap));
	if (tab.convert == 'u')
		return (print_u(tab, ap));
	if (tab.convert == 'x' || tab.convert == 'X')
		return (print_x(tab, ap));
	if (tab.convert == '%')
		return (print_percent(tab, ap));
	return (0);
}
