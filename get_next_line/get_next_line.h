/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 12:30:53 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/11/19 16:50:12 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1


#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct		s_list
{
	int				fd;
	char			*buf;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
void				*ft_memcpy(void *dst, const void *src, size_t n);

#endif
