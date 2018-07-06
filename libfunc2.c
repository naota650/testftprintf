/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfunc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:20:27 by lmartine          #+#    #+#             */
/*   Updated: 2018/07/05 20:42:12 by lmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	char	filler;
	int		i;
	int		length;

	i = -1;
	length = 0;
	while (str[length])
		length++;
	while (length - 1 > ++i)
	{
		filler = str[i];
		str[i] = str[length - 1];
		str[length - 1] = filler;
		length--;
	}
	return (str);
}

char	*ft_strcpy(char *dest, const char *src, size_t i)
{
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(ft_strlen((char *)s1) +
					ft_strlen((char *)s2))))
		return (NULL);
	str = ft_strcpy(str, s1, -1);
	str = ft_strcat(str, s2);
	return (str);
}

char	*ft_strdup(char *s1)
{
	int		length;
	char	*s2;
	int		i;

	i = -1;
	length = ft_strlen(s1);
	s2 = malloc(sizeof(*s2) * (length + 1));
	if (s2)
	{
		while (s1[++i] != '\0')
			s2[i] = s1[i];
		s2[i] = '\0';
	}
	return (s2);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 && *s2 && *s1 == *s2)
		s1++ && s2++;
	return (*(unsigned char*)s1) - *((unsigned char*)s2);
}
