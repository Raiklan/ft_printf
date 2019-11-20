/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:51:03 by saich             #+#    #+#             */
/*   Updated: 2019/11/20 16:21:59 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_tab
{
	int			minus;
	int			zero;
	int			dot;
	int			min_w;
	int			precise;
	char		convert;
}				t_tab;

int				ft_printf(char const *format, ...);
int				make_tab(t_tab *tab, char *format, va_list *ap);
int				check_minus(char c);
int				check_conversion(char c);
int				check_form(char *format);
int				print_and_count(t_tab tab, va_list *ap);
char			*sp_malloc(int size);
void			free_all(void *ptr);
int				print_c(t_tab tab, va_list ap);
int				print_s(t_tab tab, va_list ap);
int				print_d(t_tab tab, va_list ap);
int				print_u(t_tab tab, va_list *ap);
int				print_x(t_tab tab, va_list *ap);
int				print_percent(t_tab tab, va_list ap);
int				print_p(t_tab tab, va_list *ap);

#endif
