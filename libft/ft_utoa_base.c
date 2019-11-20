/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:05:22 by saich             #+#    #+#             */
/*   Updated: 2019/11/20 16:07:39 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nbr_by_base(unsigned int nbr, int base_len)
{
	int cnt;

	if (nbr == 0)
		return (1);
	cnt = 0;
	while (nbr > 0)
	{
		nbr = nbr / base_len;
		cnt++;
	}
	return (cnt);
}

char		*ft_utoa_base(unsigned int n, char *base)
{
	char			*res;
	int				len;
	int				base_len;

	base_len = ft_strlen(base);
	len = len_nbr_by_base(n, base_len);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = base[n % base_len];
		n = n / base_len;
		len--;
	}
	return (res);
}
