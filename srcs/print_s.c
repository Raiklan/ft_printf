/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:54:21 by wpark             #+#    #+#             */
/*   Updated: 2020/02/11 18:19:17 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*copy_ret(unsigned int size, unsigned int len, char *s, t_tab tab)
{
	char			*ret;
	unsigned int	space;
	unsigned int	i;

	if (!(ret = sp_malloc(size)))
		return (0);
	i = 0;
	if (tab.minus)
		while (len--)
			ret[i++] = *s++;
	else
	{
		space = size - len;
		while (space--)
		{
			if (tab.zero)
				ret[i] = '0';
			i++;
		}
		while (len--)
			ret[i++] = *s++;
	}
	return (ret);
}

int			print_s(t_tab tab, va_list *ap)
{
	char	*ret;
	char	*s;
	int		len;
	int		size;

	s = va_arg(*ap, char*);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	len = (tab.precise != -1 && len > tab.precise) ? tab.precise : len;
	size = (len > tab.min_w) ? len : tab.min_w;
	if (!(ret = copy_ret(size, len, s, tab)))
		return (0);
	write(1, ret, size);
	free_all(ret);
	return (size);
}
