#include "get_next_line.h"

size_t	f_strlen(char *s)
{
	size_t	res;

	if (!s)
		return (0);
	res = 0;
	while (s[res] != '\0')
		res++;
	return (res);
}

/*Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’*/
char	*f_strjoin(char *s1, char *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(f_strlen(s1) + f_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*f_strdup(char *s)
{
	char			*res;
	unsigned int	i;

	if (!s)
		return (f_strdup(""));
	res = (char *)malloc (f_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*locates the first occurrence of c in s and locate \0*/
char	*f_strchr(char *s, int c)
{
	char			*res;
	unsigned int	i;

	res = (char *)s;
	i = 0;
	while (res[i] != (char)c)
	{
		if (res[i] == '\0')
			return (NULL);
		i++;
	}
	return (&res[i]);
}
