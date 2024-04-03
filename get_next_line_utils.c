/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <borgiba85@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:57:26 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/04/03 01:25:03 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// buffer, buffer_size 3
// static remainder = abcdef\n;
//abcdef\nabcdef\n
// ret = 
// first function to read into buffer and remainder
// second function to make a string we gonna return, by copying from remainder
// and thir function to delete what we copied from the remainder by allocating again and freeing the first

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
		return (NULL);
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

// char	*ft_strdup(const char *str)
// {
// 	char	*nstr;
// 	size_t	i;

// 	i = 0;
// 	nstr = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
// 	if (!nstr)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		nstr[i] = str[i];
// 		i++;
// 	}
// 	nstr[i] = '\0';
// 	return (nstr);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*dest;
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (start + len > ft_strlen(s))
// 		len = ft_strlen(s) - start;
// 	i = 0;
// 	dest = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!dest)
// 		return (NULL);
// 	while (i < len && s[start + i] != '\0')
// 	{
// 		dest[i] = s[start + i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// char	*ft_strchr(const char *str, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == (char)c)
// 			return ((char *)str + i);
// 		i++;
// 	}
// 	if (str[i] == (char)c)
// 		return ((char *)str + i);
// 	return (0);
// }

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
//	i = 0;
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

// char	*new_line(char *old_line)
// {
// 	int		i;
// 	int		j;
// 	char	*str;

// 	i = 0;
// 	while (old_line[i] && old_line[i] != '\n')
// 		i++;
// 	if (!old_line[i])
// 	{
// 		free(old_line);
// 		return (NULL);
// 	}
// 	str = (char *)malloc(sizeof(char) * ft_strlen(old_line) - i + 1);
// 	if (!str)
// 		return (NULL);
// 	i++;
// 	j = 0;
// 	while (old_line[i])
// 		str[j++] = old_line[i++];
// 	str[j] = '\0';
// 	free(old_line);
// 	return (str);
// }

// @@@@@@@@@@@@@@@@@@@@@@@@@@ TEST @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// #include "get_next_line.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(1 * sizeof(char));
// 		if (!s1)
// 			return (NULL);
// 		s1[0] = '\0';
// 	}
// 	if (!s1 || !s2)
// 		return (NULL);
// 	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	while (s1[++i] != '\0')
// 		str[i] = s1[i];
// 	while (s2[j] != '\0')
// 		str[i++] = s2[j++];
// 	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
// 	free(s1);
// 	return (str);
// }

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

char	*new_line(char *old_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (old_line[i] && old_line[i] != '\n')
		i++;
	if (!old_line[i])
	{
		free(old_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(old_line) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (old_line[i])
		str[j++] = old_line[i++];
	str[j] = '\0';
	free(old_line);
	return (str);
}
