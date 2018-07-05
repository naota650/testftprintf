#include "ft_printf.h"

int		ft_nbrlen(int number, int i)
{
	while (number != 0)
	{
		number /= 10;
		i++;
	}
	return (i);
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

char	*ft_strdup(char *s1, int i)
{
	int		length;
	char	*s2;

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

int		ft_wstrlen(const wchar_t *str)
{
	int	len;

	len = 0;
	while (str[len] != L'\0')
		len++;
	return (len);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 && *s2 && *s1 == *s2)
		s1++ && s2++;
	return (*(unsigned char*)s1) - *((unsigned char*)s2);
}
