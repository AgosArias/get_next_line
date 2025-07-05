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
	char	*line_to_read;
	char	*linetmp;
	
	index = ft_index(*line, '\n');
	size = 1;
	line_to_read = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (line_to_read == NULL)
	{
		free(*line);
		*line = NULL;
		free(line_to_read);
		return ;
	}
	while (index == -1 && size > 0)
	{
		size = read(fd, line_to_read, BUFFER_SIZE);
		if (size < 1)
			break;
		line_to_read[size] = '\0';
		index = ft_index(line_to_read, '\n');
		if (*line != NULL )
		{
			linetmp = ft_strjoin(*line, line_to_read);
			free(*line);
			*line = linetmp;
		}
		else
		{
			*line = ft_strdup(line_to_read);
		}
	}
	
	free(line_to_read);
	return ;
}

char	*ft_extract_line(char **line)
{
    int     index;
    char    *extracted_line;
    char    *linetmp;
    
    if (*line == NULL || **line == '\0')
        return (NULL);
    index = ft_index(*line, '\n');
    if (index >= 0)
    {
        extracted_line = ft_substr(*line, 0, index + 1);
        linetmp = ft_substr(*line, index + 1, ft_strlen(*line) - index - 1);
        free(*line);
        *line = linetmp;
        return (extracted_line);
    }
    extracted_line = ft_strdup(*line);
    free(*line);
    *line = NULL;
    return (extracted_line);
}


char	*get_next_line(int fd)
{
	static char *readline;
	char        *line;
	
	ft_read(fd, &readline);
	if (readline == NULL)
		return (NULL);
	line = ft_extract_line(&readline);
	if (!line || !*line)
	{
		free(line);
		free(readline);
		readline = NULL;
		line = NULL;
		return (NULL);
	}
	
	return (line);
}

