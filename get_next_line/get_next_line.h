/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 12:30:53 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/11/14 16:17:44 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1


#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr(const chr *s, int c);

#endif
