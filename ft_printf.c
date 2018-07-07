/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:21:30 by lmartine          #+#    #+#             */
/*   Updated: 2018/07/07 16:34:09 by lmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(const char *format, va_list args, int *bytes)
{
	t_variable		var;
	int				i;
	int				j;

	i = -1;
	j = ft_strlen((char*)format);
	while (format[++i])
	{
		init_var(&var);
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar('%', &var);
			i += 1;
		}
		else if (format[i] == '%')
		{
			if (parse_format((char*)format, &i, &var, args))
				convert_variable(&var, args);
			else if (format[i])
				ft_putchar(format[i], &var);
		}
		else if (i < j)
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
