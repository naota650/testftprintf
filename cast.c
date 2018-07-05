/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:22:49 by lmartine          #+#    #+#             */
/*   Updated: 2018/07/04 21:43:41 by lmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_var(t_variable *var)
{
	var->bytes = 0;
	var->num = 0;
	var->space = 0;
	var->minus = 0;
	var->pound = 0;
	var->zero = 0;
	var->plus = 0;
	var->width = 0;
	var->prec = 0;
	var->conv = 0;
	var->mod = 0;
	var->prec_exist = 0;
}

char	*ft_mod_cast(va_list args, t_variable *var, int base)
{
	var->num += 1;
	if (!var->mod)
		return (ft_itoa((va_arg(args, ssize_t)), var, 1, 0));
	else if (ft_strcmp(var->mod, "z") == 0)
		return (ft_itoa_smax(va_arg(args, ssize_t)));
	else if (ft_strcmp(var->mod, "j") == 0)
		return (ft_itoa_smax(va_arg(args, intmax_t)));
	else if (ft_strcmp(var->mod, "ll") == 0)
		return (ft_itoa_smax(va_arg(args, long long)));
	else if (ft_strcmp(var->mod, "l") == 0)
		return (ft_itoa_smax(va_arg(args, long)));
	else if (ft_strcmp(var->mod, "hh") == 0)
		return (ft_itoa_smax((char)va_arg(args, int)));
	else if (ft_strcmp(var->mod, "h") == 0)
		return (ft_itoa((short)va_arg(args, int), var, 1, 0));
	else
		return (ft_itoabase_umax(va_arg(args, intmax_t), base, var));
}

char	*ft_hex_cast(va_list args, t_variable *var, int base)
{
	var->num += 1;
	if (!var->mod)
		return (ft_itoabase_umax((va_arg(args, unsigned int)), base, var));
	else if (ft_strcmp(var->mod, "z") == 0)
		return (ft_itoabase_umax(va_arg(args, ssize_t), base, var));
	else if (ft_strcmp(var->mod, "j") == 0)
		return (ft_itoabase_umax(va_arg(args, intmax_t), base, var));
	else if (ft_strcmp(var->mod, "ll") == 0)
		return (ft_itoabase_umax(va_arg(args, long long), base, var));
	else if (ft_strcmp(var->mod, "l") == 0)
		return (ft_itoabase_umax(va_arg(args, long), base, var));
	else if (ft_strcmp(var->mod, "hh") == 0)
		return (ft_itoabase_umax((char)va_arg(args, int), base, var));
	else if (ft_strcmp(var->mod, "h") == 0)
		return (ft_itoabase_umax((short)va_arg(args, int), base, var));
	else
		return (ft_itoabase_umax(va_arg(args, intmax_t), base, var));
}
