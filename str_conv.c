/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:27:02 by lmartine          #+#    #+#             */
/*   Updated: 2018/07/07 16:29:24 by lmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(char *str)
{
	int i;
	int nb;
	int sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (!str)
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (sign * nb);
}

char	*ft_otoa(unsigned long int number, t_variable *var)
{
	char				*str;
	unsigned int		i;
	unsigned long int	x;

	x = number;
	var->num += 1;
	i = 0;
	str = (char*)malloc(sizeof(char) * 24);
	if (number == 0 && !var->pound && var->prec_exist)
		return ("");
	if (number == 0)
	{
		str[i] = '0';
		i++;
	}
	while (number)
	{
		str[i] = (number % 8) + 48;
		number /= 8;
		i++;
	}
	str[i] = '\0';
	ft_strrev(str);
	(x != 0 && var->pound) ? str = ft_strjoin("0", str) : 0;
	return (str);
}

char	*ft_ptoa(unsigned long int number, t_variable *var)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * 12);
	if (number == 0)
		str[i] = '0';
	while (number && var->conv == 'p')
	{
		str[i++] = "0123456789abcdef"[number % 16];
		number /= 16;
	}
	str = ft_strrev(str);
	str = ft_strjoin("0x", str);
	return (str);
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;

	i = ft_strlen(dest);
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
