/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:23:33 by lmartine          #+#    #+#             */
/*   Updated: 2018/07/07 16:02:53 by lmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_check(char *str, char c, t_variable *var)
{
	int i;

	i = -1;
	while (str[++i])
		if (c == str[i])
		{
			var->conv = c;
			return (1);
		}
	return (0);
}

void	init_mod(char *s, int *i, t_variable *var)
{
	(s[*i] == 'h' && s[*i + 1] == 'h') ? var->mod = "hh" : 0;
	(s[*i] == 'h' && s[*i + 1] != 'h') ? var->mod = "h" : 0;
	(s[*i] == 'l' && s[*i + 1] != 'l') ? var->mod = "l" : 0;
	(s[*i] == 'l' && s[*i + 1] == 'l') ? var->mod = "ll" : 0;
	(s[*i] == 'j') ? var->mod = "j" : 0;
	(s[*i] == 'z') ? var->mod = "z" : 0;
	if (var->mod)
		*i += ft_strlen(var->mod);
}

void	init_flag(char *str, t_variable *var, int *i)
{
	while (str[*i] && (str[*i] == '0' || str[*i] == '+' ||
				str[*i] == '-' || str[*i] == '#' || str[*i] == ' '))
	{
		if (str[*i] == '0') 
			var->zero += 1;
		if (str[*i] == '-')
			var->minus += 1;
		if (str[*i] == '+')
			var->plus += 1;
		if (str[*i] == '#')
			var->pound += 1;
		if (str[*i] == ' ')
			var->space += 1;
		*i += 1;
	}
}

void	parse_prec_width(char *str, int *i, t_variable *var, va_list args)
{
	if (str[*i] && (((str[*i] > '0' && str[*i] <= '9'))
				|| (str[*i] == '*' && str[*i - 1] != '*')))
	{
		if (str[*i] == '*' && str[*i - 1] != '*')
		{
			var->width = va_arg(args, int);
			*i += 1;
		}
		else
		{
			var->width = (ft_atoi(&str[*i]));
			*i += ft_nbrlen(ft_atoi(&str[*i]));
		}
	}
	if (str[*i] && (str[*i] == '.'))
	{
		*i += 1;
		var->prec_exist += 1;
		if (str[*i] == '*')
			var->prec = va_arg(args, int);
		else if (str[*i] && str[*i] >= '0' && str[*i] <= '9')
			var->prec = (ft_atoi(&str[*i]));
		while ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '*')
			*i += 1;
	}
}

int		parse_format(char *str, int *i, t_variable *var, va_list args)
{
	*i += 1;
	init_flag(str, var, i);
	parse_prec_width(str, i, var, args);
	init_mod(str, i, var);
	if (conv_check("sSpdDioOuUxXcC", str[*i], var))
		return (1);
	if (var->zero)
		ft_putstr(str_zeros("", var), var);
	if (var->width)
	{
		var->width -= 1;
		(var->minus) ? ft_putchar(str[*i], var) : 0;
		(var->minus) ? *i += 1 : 0;
		ft_putstr(ft_spaces("", var), var);
	}
	return (0);
}
