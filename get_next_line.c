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

char	ft_read(int fd)
{
	char	*read_buffer;
	size_t bytes_read;

	bytes_read = 1;
	read_buffer = (char *)malloc(BUFFER_SIZE + 1);
	while (1)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			ft_free(read_buffer);
			return;
		}
		read_buffer[bytes_read] = '\0';
		if (!ft_strchr(read_buffer, '\n'))
		{
			
		}
		
		
	}
	
}

char	ft_extract_line()
{

}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;

	line = ft_read(fd);
	if (line == NULL)
		return (NULL);
	line = ft_extract_line();
}