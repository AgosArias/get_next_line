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

char	*ft_read(int fd, char *buffer)
{
	char	*read_buffer;
	size_t bytes_read;
	char	*line_tmp;

	bytes_read = 1;
	read_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			ft_free(read_buffer);
			return (NULL);
		}
		read_buffer[bytes_read] = '\0';
		if (!buffer)
			buffer = ft_strdup(read_buffer);
		else
		{
			line_tmp = ft_strjoin(buffer, read_buffer);
			ft_free(buffer);
			buffer = line_tmp;
		}
	}
	ft_free(read_buffer);
	return (buffer);
}

char	*ft_extract_line(char *buffer)
{
	char	*line;

	if (!buffer)
		return (NULL);
	if (!ft_strchr(buffer, '\n'))
	{
		line = ft_strdup(buffer);
		ft_free(buffer);
	}
	else
	{
		line = 
		buffer = ft_strchr(buffer, '\n');
	}
	return (line);
}


char	*ft_(char *buffer, int c)
{
	int		count;
	char	*d;

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


char *get_next_line(int fd)
{
	static char *buffer;
	char *line;

	buffer = ft_read(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = ft_extract_line(buffer);
	if (!line)
		ft_free(buffer);

} 

/*

        extracted_line = ft_substr(*line, 0, index + 1);
        linetmp = ft_substr(*line, index + 1, ft_strlen(*line) - index - 1);
        free(*line);
        *line = linetmp;
        return (extracted_line);
    }
}*/