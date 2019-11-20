/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:52:15 by saich             #+#    #+#             */
/*   Updated: 2019/11/20 16:28:09 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
char			*ft_itoa_base(int nbr, char *base);
char			*ft_utoa_base(unsigned int n, char *base);

#endif
