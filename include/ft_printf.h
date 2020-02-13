/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:51:38 by wpark             #+#    #+#             */
/*   Updated: 2020/02/11 17:30:16 by saich            ###   ########.fr       */
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

int				ft_printf(const char *form, ...);
int				check_form(char *f);
int				check_minus(char c);
int				check_conversion(char c);
int				make_tab(t_tab *tab, char *form, va_list *ap);
int				print_and_count(t_tab tab, va_list *ap);
int				print_c(t_tab tab, va_list *ap);
int				print_s(t_tab tab, va_list *ap);
int				print_p(t_tab tab, va_list *ap);
int				print_d(t_tab tab, va_list *ap);
int				print_u(t_tab tab, va_list *ap);
int				print_x(t_tab tab, va_list *ap);
int				print_percent(t_tab tab, va_list *ap);
char			*sp_malloc(int size);
char			*zero_malloc(int size);
void			free_all(void *ptr);

#endif
