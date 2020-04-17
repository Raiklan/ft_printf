/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 09:37:28 by saich             #+#    #+#             */
/*   Updated: 2020/04/17 20:47:28 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nbr_by_base(unsigned long nbr, int b_len)
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

static void	put_null_and_sign(char *res, int len, int sign)
{
	res[len] = '\0';
	if (sign == 1)
		res[0] = '-';
}

char		*ft_itoa_base(long nbr, char *base, int b_len)
{
	unsigned long	n;
	char			*res;
	int				len;
	int				sign;

	len = 0;
	sign = 0;
	if (nbr < 0)
	{
		len++;
		n = -nbr;
		sign = 1;
	}
	else
		n = nbr;
	len = len + len_nbr_by_base(n, b_len);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	put_null_and_sign(res, len, sign);
	while (--len >= sign)
	{
		res[len] = base[n % b_len];
		n = n / b_len;
	}
	return (res);
}
