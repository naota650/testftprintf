/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:21:30 by lmartine          #+#    #+#             */
/*   Updated: 2018/07/04 19:39:32 by lmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(const char *format, va_list args, int *bytes)
{
	t_variable		var;
	int				i;
	int				x;

	i = -1;
	x = ft_strlen((char*)format);
	while (format[++i])
	{
		ft_init_var(&var);
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar('%', &var);
			i += 1;
		}
		else if (format[i] == '%')
		{
			if (ft_parse((char*)format, &i, &var, args))
				ft_handle_it(&var, args);
			else if (format[i])
				ft_putchar(format[i], &var);
		}
		else if (i < x)
			ft_putchar(format[i], &var);
		*bytes += var.bytes;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			bytes;

	bytes = 0;
	va_start(args, format);
	check_format(format, args, &bytes);
	va_end(args);
	return (bytes);
}
