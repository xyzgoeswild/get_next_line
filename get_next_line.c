/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <borgiba85@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:57:21 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/04/03 00:49:53 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_file(int fd, char *string, char *buffer)
{
    int bytes_read;

    bytes_read = 1;
    while (!ft_strchr(string, '\n') && bytes_read > 0) 
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
          return (NULL);

        buffer[bytes_read] = '\0';
        string = ft_strjoin(string, buffer);
    }
    free(buffer);
    return (string);
}

char  *get_next_line(int fd)
{
    char  *line;
   char  *buffer;
    static char *string;
    
   buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    
    if (BUFFER_SIZE <= 0 || fd < 0)
       return (NULL);
    string = ft_read_file(fd, string, buffer);
    
    line = ft_copy_line(string);
    string = new_line(string);
    return (line);
}


//&&&&&&&&&&&&&&&&& DELETE &&&&&&&&&&&&&&&&&&&&&&&&

// char	*ft_copy_line(char *line)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	if (!line[i])
// 		return (NULL);
// 	while (line[i] && line[i] != '\n')
// 		i++;
// 	str = (char *)malloc(sizeof(char) * (i + 2));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (line[i] && line[i] != '\n')
// 	{
// 		str[i] = line[i];
// 		i++;
// 	}
// 	if (line[i] == '\n')
// 	{
// 		str[i] = line[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }