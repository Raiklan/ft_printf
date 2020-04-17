/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:59:14 by saich             #+#    #+#             */
/*   Updated: 2020/04/17 20:47:24 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
char	*ft_itoa_base(long nbr, char *base, int b_len);
char	*ft_utoa_base(unsigned int n, char *base, int b_len);

#endif
