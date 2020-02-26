/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 12:30:53 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/12/03 15:23:42 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int				get_next_line(int fd, char **line);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const	char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strjoin(char const *s1, char const *s2, int *res);
char			*ft_strdup(const char *s1, int *res);
char			*ft_substr(char *s, unsigned int start, size_t len, int *res);
char			*ft_strchr(const char *s, int c);

#endif
