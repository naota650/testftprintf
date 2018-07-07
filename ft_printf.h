/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 20:04:47 by lmartine          #+#    #+#             */
/*   Updated: 2018/07/07 16:47:06 by lmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_variable
{
	int			bytes;
	char		conv;
	int			minus;
	char		*mod;
	int			num;
	int			plus;
	int			pound;
	int			prec;
	int			prec_exist;
	int			space;
	int			width;
	int			zero;
}				t_variable;

int				conv_check(char *s, char c, t_variable *var);
void			convert_variable(t_variable *var, va_list args);
void			do_flags(char *str, t_variable *var);
char			*hex_cast(va_list args, t_variable *var, int base);
void			init_var(t_variable *var);
int				intmaxlen(intmax_t num);
void			init_mod(char *s, int *i, t_variable *var);
void			init_flag(char *s, t_variable *var, int *i);
char			*mod_cast(va_list args, t_variable *var, int base);
int				num_base_length(size_t num, int base);
void			parse_prec_width(char *s, int *i,
		t_variable *var, va_list args);
int				parse_format(char *s, int *i, t_variable *var, va_list args);
char			*prec_copy(char *str, t_variable *var);
char			*str_zeros(char *s, t_variable *var);
void			ft_putchar(char c, t_variable *var);
void			ft_putstr(char *s, t_variable *var);
char			*ft_strrev(char *str);
int				ft_strlen(char *s);
char			*ft_strcpy(char *dest, const char *src);
int				ft_nbrlen(int number);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(char *s1);
int				ft_wstrlen(const wchar_t *str);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcat(char *dest, const char *src);
char			*ft_spaces(char *str, t_variable *var);
void			ft_putwstr(wchar_t *ws, t_variable *var);
wchar_t			*ft_wchrtostr(wchar_t wchar);
char			*ft_itoa(int nbr, t_variable *var, int length, int sign);
char			*ft_itoabase(size_t num, int base, t_variable *var);
char			*ft_itoa_intmax(intmax_t num);
int				ft_atoi(char *str);
char			*ft_otoa(unsigned long int number, t_variable *var);
char			*ft_ptoa(unsigned long int number, t_variable *var);
int				ft_printf(const char *format, ...);

#endif
