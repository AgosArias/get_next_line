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

void    ft_free(char *pointer)
{
	if (pointer != NULL)
		free(pointer);
}

char	*ft_strchr(char *s, int c)
{
	int		count;
	char	*d;

	if (!s)
		return (NULL);
	d = (char *)s;
	count = 0;
	while (d[count])
	{
		if (d[count] == (char)c)
			return (&d[count]);
		count++;
	}
	if ((char)c == '\0')
		return (&d[count]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*w;
	int		a;
	int		b;

	b = 0;
	a = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if(!s2)
		return (ft_strdup(s1));	
	w = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (w == NULL)
		return (NULL);
	while (s1[a] != '\0')
	{
		w[a++] = s1[a];
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

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (-1);
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

	char	*ft_strdup(char *src)
{
	int		i;
	char	*c;

	if (!src)
		return (NULL);
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