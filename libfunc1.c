#include "ft_printf.h"
#include <limits.h>

void	ft_putchar(char c, t_variable *var)
{
	write(1, &c, 1);
	var->bytes += 1;
}

void	ft_putstr(char *str, t_variable *var, int i)
{
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

char	*ft_strrev(char *str, int i, int length)
{
	char	buff;

	while (str[length])
		length++;
	while (length - 1 > ++i)
	{
		buff = str[i];
		str[i] = str[length - 1];
		str[length - 1] = buff;
		length--;
	}
	return (str);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src, size_t i)
{
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

