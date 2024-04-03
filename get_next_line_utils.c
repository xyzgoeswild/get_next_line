/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <borgiba85@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:57:26 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/04/03 05:30:10 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
	{
		free(s1);
		return (NULL);
	}
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;
 
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_copy_line(char *line)
{
    int i;
    char *new_line;

    i = 0;
    if (!line[i])
      return (NULL);

	while (line[i] && line[i] != '\n')
		i++;
    new_line = (char *) malloc(sizeof(char) * (i + 2));
    if (!new_line)
      return (NULL);
	i = 0;
    while (line[i] && line[i] != '\n')
    {
      new_line[i] = line[i];
      i++;
    }
	if (line[i] == '\n')
	{
		new_line[i] = line[i];
		i++;
	}
    new_line[i] = '\0';
    return (new_line);
}

char	*ft_remainder(char *previous_line)
{
	int i;
	int j;
	char *remainder;

	i = 0;
	if (!previous_line[i])
	{
		free(previous_line);
		return (NULL);
	}
	while (previous_line[i] && previous_line[i] != '\n')
		i++;
	
	remainder = (char *) malloc(sizeof(char) * (ft_strlen(previous_line) - i + 1));
	if (!remainder)
		return (NULL);
	i++;
	j = 0;
	while (previous_line[i])
		remainder[j++] = previous_line[i++];
	remainder[j] = '\0';
	free(previous_line);
	return (remainder);
}