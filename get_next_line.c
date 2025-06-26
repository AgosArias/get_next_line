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

char	*ft_read(int fd)
{
	char 		*readline;
	ssize_t		size;
	char		*line;
	int len;

	len = 0;
	if(readline != NULL)
	{
		line = readline;
		free(readline);
	}
	readline = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (readline == NULL)
		return (NULL);
	size = read(fd, readline, BUFFER_SIZE);
	if (size < 1)
		return (NULL);
	while (size > 0 && len != size)
	{
		while (readline[len] != '\0' && readline[len] != '\n')
			len++;
		readline[len] = '\n';
		line = ft_strjoin(line, ft_substr(readline, 0, len));
		return (line);
		size = read(fd, readline, BUFFER_SIZE);
	}

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
