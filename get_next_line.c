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
	int		bytes_read;
	char	*buffer_tmp;
	
	bytes_read = 1;
	read_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	while ((!buffer ||!ft_strchr(buffer, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			ft_free(read_buffer);
			ft_free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
		{
			ft_free(read_buffer);
			return (buffer);
		}
		read_buffer[bytes_read] = '\0';
		if (!buffer)
			buffer = ft_strdup(read_buffer);
		else
		{
			buffer_tmp = buffer;
			buffer = ft_strjoin(buffer, read_buffer);
			ft_free(buffer_tmp);
		}		
	}
	ft_free(read_buffer);
	return (buffer);
}

char	*ft_extract_line(char *buffer)
{
	char	*line;
	int		i;
	int j;
	
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
char	*ft_update_buffer(char *buffer)
{
	int		j;
	int		i;
	char	*buffer_tmp;
	
	if (!buffer || buffer[0] == '\0' ||!ft_strchr(buffer, '\n'))
	{
		ft_free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0' )
		i++;
	if (buffer[i] == '\n')
		i++;
	if(ft_strlen(buffer) == 0)
	{
		ft_free(buffer);
		return(NULL);
	}
	buffer_tmp = (char *)malloc(sizeof(char)* (ft_strlen(buffer)-i+1));
	j = 0;
	while (buffer[i] != '\0')
		buffer_tmp[j++] = buffer[i++];
	buffer_tmp[j] = '\0';
	ft_free(buffer);
	buffer = buffer_tmp;
	return (buffer);
}
char *get_next_line(int fd)
{
	static char *buffer;
	char *line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer || buffer[0] == '\0' ||  *buffer == '\0')
	{
		ft_free(buffer);
		return (NULL);
	}
	line = ft_extract_line(buffer);
	buffer = ft_update_buffer(buffer);
	if (!line)
	{
		ft_free(buffer);
		return(NULL);
	}
	return (line);
} 
