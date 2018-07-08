/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 21:27:46 by lmartine          #+#    #+#             */
/*   Updated: 2018/07/07 17:03:35 by lmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putwstr(wchar_t *ws, t_variable *var)
{
	int i;

	i = -1;
	var->width -= (ft_wstrlen(ws) - var->prec);
	var->minus ? var->zero = 0 : 0;
	if (var->width > 0 && !var->minus)
		while (var->width)
		{
			var->zero ? write(1, "0", 1) : write(1, " ", 1);
			var->width -= 1;
		}
	while (ws[++i])
	{
		if (var->prec && var->prec < ft_wstrlen(ws))
		{
			while (var->prec--)
				ft_putchar(ws[i], var);
			break ;
		}
		ft_putchar(ws[i], var);
		var->bytes += 1;
	}
	if (var->width > 0 && var->minus)
		while (var->width)
		{
			var->zero ? write(1, "0", 1) : write(1, " ", 1);
			var->width -= 1;
		}
}

wchar_t		*ft_wchrtostr(wchar_t wchar)
{
	wchar_t	*wstr;

	wstr = (wchar_t *)malloc(sizeof(wchar) * 2);
	if (wstr)
	{
		wstr[0] = wchar;
		wstr[1] = L'\0';
	}
	return (wstr);
}

char		*str_zeros(char *str, t_variable *var)
{
	char	temp[var->prec + 1];
	int		i;

	i = -1;
	if (var->prec < 0)
		return (str);
	while (++i < var->prec)
		temp[i] = '0';
	temp[i] = '\0';
	if (str[0] == '-')
	{
		str = ft_strjoin(temp, &str[1]);
		str = ft_strjoin("-", str);
	}
	else
		str = ft_strjoin(temp, str);
	var->zero = 0;
	return (str);
}

char		*ft_spaces(char *str, t_variable *var)
{
	char	temp[var->width + 1];
	int		i;
	char	filler[2];

	i = 0;
	filler[0] = str[0];
	filler[1] = '\0';
	if (var->width < 1)
		return (str);
	while (i < var->width)
	{
		temp[i] = (var->zero) ? '0' : ' ';
		i++;
	}
	temp[i] = '\0';
	if ((filler[0] == '-' || filler[0] == '+') && var->zero && var->num)
	{
		str = ft_strjoin(temp, &str[1]);
		str = ft_strjoin(filler, str);
	}
	else
		str = (var->minus) ? ft_strjoin(str, temp) : ft_strjoin(temp, str);
	return (str);
}

char		*prec_copy(char *str, t_variable *var)
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
