/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:56:26 by bkuksa            #+#    #+#             */
/*   Updated: 2019/03/28 12:44:51 by bkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

# define MASK1 49280
# define MASK2 14712960
# define MASK3 4034953344

typedef struct	s_printf
{
	va_list		arg;
	char		*p;
	char		c;
	char		*s;
	int			tup;
	int			z;
	int			n_spec;
	char		ch;
	uintmax_t	k;
	intmax_t	v;
	int			min;
	size_t		len;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			prec;
	int			n;
}				t_printf;

int				ft_printf(const char *str, ...);
int				main(void);
int				ft_printf_all(const char *form, t_printf *bog,
				int count, int val);
int				ft_valid_bog(const char *str, size_t *i);
int				ft_valid(const char c);
int				ft_conversion(const char c);
int				ft_flag(const char c);
int				ft_precision(const char c);
int				ft_mod(const char c);
int				ft_sharing(const char *str, size_t len, int val, t_printf *bog);
int				ft_write(const char *form, size_t j, t_printf *bog);
int				ft_bog_list(t_printf *bog);
char			*ft_tipe_one(t_printf *bog);
void			ft_print_str(t_printf *bog, int n);
char			*ft_print_int(t_printf *bog, char c);
char			*ft_print_x(t_printf *bog, char c);
char			*ft_hex(uintmax_t n, int x, char *s);
char			*ft_char(t_printf *bog);
char			*ft_print_uo(t_printf *bog, char c);
void			ft_print_f(t_printf *bog, int n);
char			*ft_itoaf(long double n, int p, t_printf *bog, int k);
char			*ft_print_p(t_printf *bog);
char			*ft_apgrd(t_printf *bog);
void			ft_app_col(const char *str, size_t i, t_printf *bog);
void			ft_hash_plus(t_printf *bog, size_t i);
void			ft_space(t_printf *bog, size_t i);
void			ft_zero(t_printf *bog, size_t i, int n);
void			ft_str_zero(int i, int j, t_printf *bog, int k);
void			ft_minus(t_printf *bog, size_t i);
char			*ft_str_minus(int k, t_printf *bog, int c);
void			ft_int_s(t_printf *bog, size_t i);
void			ft_inttup_f(t_printf *bog, size_t i, char *str, int n);
char			*ft_write_zero(t_printf *bog, int n, int i);
long double		ft_pld(long double d);
void			ft_bog_upp(t_printf *bog);
void			ft_unicod_s(t_printf *bog);
char			*ft_unicod_c(t_printf *bog, wchar_t z, char *str);
void			ft_mod_ouxid(t_printf *bog);
uintmax_t		ft_arg_oux(t_printf *bog);
intmax_t		ft_arg_id(t_printf *bog);
char			*ft_itoa_long(intmax_t n);
long double		ft_mod_float(t_printf *bog);
char			*ft_float_god(char *s, char *s2, int p);
char			*ft_strjoin_fix(char *s1, char *s2, int n);
void			ft_del_bog_s(t_printf *bog, char *str);
char			*ft_itoaf_2(char *str, long double *n, int *k, int p);
char			*ft_prec_sc(int n, t_printf *bog);

#endif
