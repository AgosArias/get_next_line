/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:24:33 by aarias-d          #+#    #+#             */
/*   Updated: 2025/06/24 18:57:33 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	if (i == 0)
		return (0);
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*w;
	int		x;

	if (s == NULL )
		return (NULL);
	if (len == 0 || start >= (unsigned int)ft_strlen(s))
		return (NULL);
	if ((size_t)ft_strlen(s) - (size_t)start < len)
		len = (size_t)ft_strlen(s) - (size_t)start;
	w = (char *)malloc(sizeof(char) * (len + 1));
	if (w == NULL)
		return (NULL);
	x = 0;
	while ((size_t)x < len)
	{
		w[x] = s[x + start];
		x++;
	}
	w[x] = '\0';
	return (w);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*w;
	int		a;
	int		b;

	b = 0;
	a = 0;
	w = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (w == NULL)
		return (NULL);
	while (s1[a] != '\0')
	{
		w[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
	{
		w[a + b] = s2[b];
		b++;
	}
	w[a + b] = '\0';
	return (w);
}


int	ft_index(const char *s, int c)
{
	int	count;

	if (!s)
		return (-1);
	count = 0;
	while (s[count])
	{
		if (s[count] == (char)c)
			return (count);
		count++;
	}
	if ((char)c == '\0')
		return (count);
	return (-1);
}
char	*ft_strdup(char *src)
{
	int		i;
	char	*c;

	i = ft_strlen(src) + 1;
	c = (char *) malloc (i * sizeof(char));
	if (!c)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		c[i] = src[i];
		i++;
	}
	c[i] = src[i];
	return (c);
}
