/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfunc1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:24:06 by lmartine          #+#    #+#             */
/*   Updated: 2018/07/04 20:14:01 by lmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	ft_putchar(char c, t_variable *var)
{
	write(1, &c, 1);
	var->bytes += 1;
}

void	ft_putstr(char *str, t_variable *var)
{
	int i;

	i = -1;
	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (str[++i])
	{
		write(1, &str[i], 1);
		var->bytes += 1;
	}
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_nbrlen(int number)
{
	int i;

	i = 0;
	while (number != 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

int		ft_wstrlen(const wchar_t *str)
{
	int length;

	length = 0;
	while (str[length] != L'\0')
		length++;
	return (length);
}
