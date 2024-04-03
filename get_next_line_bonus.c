/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <borgiba85@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 08:32:39 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/04/03 09:57:02 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_file(int fd, char *string, char *buffer)
{
	int	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(string, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		string = ft_strjoin(string, buffer);
	}
	return (string);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*string[1024];

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(buffer);
		return (NULL);
	}
	string[fd] = ft_read_file(fd, string[fd], buffer);
	if (!string[fd])
		return (NULL);
	line = ft_copy_line(string[fd]);
	string[fd] = ft_remainder(string[fd]);
	free(buffer);
	return (line);
}