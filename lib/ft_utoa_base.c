/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:27:10 by saich             #+#    #+#             */
/*   Updated: 2020/04/17 20:47:29 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nbr_by_base(unsigned int nbr, int b_len)
{
	int count;

	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr > 0)
	{
		nbr = nbr / b_len;
		count++;
	}
	return (count);
}

char		*ft_utoa_base(unsigned int n, char *base, int b_len)
{
	char			*res;
	int				len;

	len = len_nbr_by_base(n, b_len);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = base[n % b_len];
		n = n / b_len;
		len--;
	}
	return (res);
}
