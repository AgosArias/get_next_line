/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:24:39 by aarias-d          #+#    #+#             */
/*   Updated: 2025/06/24 19:03:26 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(fd)
{
	char *readline;
	ssize_t		size;


	readline = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (readline == NULL)
		return (NULL);
	size = read(fd, readline, BUFFER_SIZE);
	if (size < 1)
		return (NULL);
	while (size > 0)
	{
		size = read(fd, readline, BUFFER_SIZE);
		if (size < 1)
			return (NULL);
	}

	readline[size] = '\0';
	int len = 0;
	while (readline[len] != '\0' && readline[len] != '\n')
		len++;
}

char	*get_next_line(int fd)
{
	static char	*readline;
	char		*line;
	ssize_t		i;
	int			len;

	/*readline = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (readline == NULL)
		return (NULL);
	i = read(fd, readline, BUFFER_SIZE);
	if (i < 1)
		return (NULL);
	readline[i] = '\0';
	len = 0;
	while (readline[len] != '\0' && readline[len] != '\n')
		len++;*/
	line = ft_substr(readline, 0, len);
	if (line == NULL)
	{
		free(readline);
		return (NULL);
	}
	line[len] = readline[len];
	free(readline);
	return (line);
}
