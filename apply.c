/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:24:47 by lmartine          #+#    #+#             */
/*   Updated: 2018/07/04 21:17:47 by lmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zeros(char *str, t_variable *var)
{
	char	block[var->prec + 1];
	int		i;

	i = -1;
	if (var->prec < 0)
		return (str);
	while (++i < var->prec)
		block[i] = '0';
	block[i] = '\0';
	if (str[0] == '-')
	{
		str = ft_strjoin(block, &str[1]);
		str = ft_strjoin("-", str);
	}
	else
		str = ft_strjoin(block, str);
	var->zero = 0;
	return (str);
}

char	*ft_spaces(char *str, t_variable *var)
{
	char	block[var->width + 1];
	int		i;
	char	edge[2];

	i = 0;
	edge[0] = str[0];
	edge[1] = '\0';
	if (var->width < 1)
		return (str);
	while (i < var->width)
	{
		block[i] = (var->zero) ? '0' : ' ';
		i++;
	}
	block[i] = '\0';
	if ((edge[0] == '-' || edge[0] == '+') && var->zero && var->num)
	{
		str = ft_strjoin(block, &str[1]);
		str = ft_strjoin(edge, str);
	}
	else
		str = (var->minus) ? ft_strjoin(str, block) : ft_strjoin(block, str);
	return (str);
}

char	*ft_chop(char *str, t_variable *var)
{
	char	*dest;
	int		i;

	i = -1;
	dest = (char*)malloc(sizeof(char) * var->prec + 1);
	while (++i < var->prec)
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}

void	ft_apply_flags(char *s, t_variable *var)
{
	if (!s)
	{
		ft_putstr("(null)", var);
		return ;
	}
	(s[0] == '-') ? var->prec += 1 : 0;
	if (!var->num)
		s = (var->prec) ? ft_chop(s, var) : s;
	s = (var->pound && var->conv == 'x' && !var->zero)
		? ft_strjoin("0x", s) : s;
	s = (var->pound && var->conv == 'X' && !var->zero)
		? ft_strjoin("0X", s) : s;
	(var->space && s[0] != '-') ? var->width -= 1 : 0;
	var->prec -= ft_strlen(s);
	(var->plus && s[0] != '-') ? var->width -= 1 : 0;
	s = (var->num) ? ft_zeros(s, var) : s;
	var->width -= ft_strlen(s);
	s = (var->plus && s[0] != '-') ? ft_strjoin("+", s) : s;
	s = ft_spaces(s, var);
	s = (var->pound && var->conv == 'x' && var->zero) ? ft_strjoin("0x", s) : s;
	s = (var->pound && var->conv == 'X' && var->zero) ? ft_strjoin("0X", s) : s;
	s = (var->space && s[0] != '-') ? ft_strjoin(" ", s) : s;
	ft_putstr(s, var);
}

void	ft_handle_it(t_variable *var, va_list args)
{
	(var->plus) ? var->space = 0 : 0;
	(var->conv == 'u' || var->conv == 'U') ? var->plus = 0 : 0;
	(var->conv == 'u' || var->conv == 'U') ? var->space = 0 : 0;
	(var->zero && var->minus) ? var->zero = 0 : 0;
	if (var->conv == 's' && !var->mod)
		ft_apply_flags(va_arg(args, char*), var);
	else if (var->conv == 'D')
		ft_apply_flags(ft_itoabase_umax(va_arg(args, long), 10, var), var);
	else if (var->conv == 'S' ||
			(var->conv == 's' && ft_strcmp("l", var->mod) == 0))
		ft_putwstr(va_arg(args, wchar_t*), var, -1);
	else if (var->conv == 'C')
		ft_putwstr((ft_wchrtostr(va_arg(args, wchar_t))), var, -1);
	else if (var->conv == 'c')
		ft_putchar(va_arg(args, int), var);
	else if (var->conv == 'o' || var->conv == 'O')
		ft_apply_flags(ft_otoa(va_arg(args, unsigned int), var), var);
	else if (var->conv == 'p')
		ft_apply_flags(ft_ptoa(va_arg(args, unsigned long int), var), var);
	else if (var->conv == 'd' || var->conv == 'i')
		ft_apply_flags(ft_mod_cast(args, var, 10), var);
	else if (var->conv == 'x' || var->conv == 'X')
		ft_apply_flags(ft_hex_cast(args, var, 16), var);
	else if (var->conv == 'u' || var->conv == 'U')
		ft_apply_flags(ft_itoabase_umax(va_arg(args, intmax_t), 10, var), var);
}
