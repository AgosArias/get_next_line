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

void	ft_read(int fd, char **line)
{
	ssize_t	size;
	int		index;
	char	*readline;
	char	*linetmp;
	
	index = ft_index(*line, '\n');
	size = 1;
	readline = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (readline == NULL)
		return ;
	while (index == -1 && size > 0)
	{
		size = read(fd, readline, BUFFER_SIZE);
		if (size < 1)
			break;
		readline[size] = '\0';
		index = ft_index(readline, '\n');
		if (*line != NULL )
		{
			linetmp = ft_strjoin(*line, readline);
			free(*line);
			*line = linetmp;
		}
		else
		{
			*line = ft_strdup(readline);
		}
	}
	free(readline);
	return ;
}

char	*ft_extract_line(char **line)
{
	int		index;
	char	*extracted_line;
	char	*linetmp;

	if (*line == NULL)
		return (NULL);
	index = ft_index(*line, '\n');
	if (index < 0)
	{
		if (**line == '\0')
		{
			free(*line);
			*line = NULL;
			return (NULL);
		}
		extracted_line = ft_strdup(*line);
		free(*line);
		*line = NULL;
		return (extracted_line);
	}
	extracted_line = ft_substr(*line, 0, index + 1);
	linetmp = ft_substr(*line, index + 1, ft_strlen(*line) - index - 1);
	free(*line);
	*line = linetmp;
	return (extracted_line);
}

char	*get_next_line(int fd)
{
	static char	*readline;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read(fd, &readline);
	line = ft_extract_line(&readline);
	return (line);
}
