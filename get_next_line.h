/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <borgiba85@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:57:29 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/04/02 23:50:18 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int c);
char    *ft_copy_line(char *line);
char	*new_line(char *old_line);

#endif