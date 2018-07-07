/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:58:06 by lmartine          #+#    #+#             */
/*   Updated: 2018/07/07 16:47:22 by lmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_flags(char *str, t_variable *var)
{
	if (!str)
	{
		ft_putstr("(null)", var);
		return ;
	}
	(str[0] == '-') ? var->prec += 1 : 0;
	if (!var->num)
		str = (var->prec) ? prec_copy(str, var) : str;
	if (!var->zero && var->pound && var->conv == 'X')
		ft_strjoin("0X", str);
	if (!var->zero && var->pound && var->conv == 'x')
		ft_strjoin("0x", str);
	(var->space && str[0] != '-') ? var->width -= 1 : 0;
	var->prec -= ft_strlen(str);
	(var->plus && str[0] != '-') ? var->width -= 1 : 0;
	str = (var->num) ? str_zeros(str, var) : str;
	var->width -= ft_strlen(str);
	str = (var->plus && str[0] != '-') ? ft_strjoin("+", str) : str;
	str = ft_spaces(str, var);
	if (var->zero && var->pound && var->conv == 'X')
		ft_strjoin("0X", str);
	if (var->zero && var->pound && var->conv == 'x')
		ft_strjoin("0x", str);
	str = (var->space && str[0] != '-') ? ft_strjoin(" ", str) : str;
	ft_putstr(str, var);
}

void	convert_variable(t_variable *var, va_list args)
{
	(var->plus) ? var->space = 0 : 0;
	(var->conv == 'u' || var->conv == 'U') ? var->plus = 0 : 0;
	(var->conv == 'u' || var->conv == 'U') ? var->space = 0 : 0;
	(var->zero && var->minus) ? var->zero = 0 : 0;
	if (var->conv == 's' && !var->mod)
		do_flags(va_arg(args, char*), var);
	else if (var->conv == 'c')
		ft_putchar(va_arg(args, int), var);
	else if (var->conv == 'C')
		ft_putwstr((ft_wchrtostr(va_arg(args, wchar_t))), var);
	else if (var->conv == 'd' || var->conv == 'i')
		do_flags(mod_cast(args, var, 10), var);
	else if (var->conv == 'D')
		do_flags(ft_itoabase(va_arg(args, long), 10, var), var);
	else if (var->conv == 'o' || var->conv == 'O')
		do_flags(ft_otoa(va_arg(args, unsigned int), var), var);
	else if (var->conv == 'p')
		do_flags(ft_ptoa(va_arg(args, unsigned long int), var), var);
	else if (var->conv == 'S' ||
			(var->conv == 's' && ft_strcmp("l", var->mod) == 0))
		ft_putwstr(va_arg(args, wchar_t*), var);
	else if (var->conv == 'u' || var->conv == 'U')
		do_flags(ft_itoabase(va_arg(args, intmax_t), 10, var), var);
	else if (var->conv == 'x' || var->conv == 'X')
		do_flags(hex_cast(args, var, 16), var);
}
