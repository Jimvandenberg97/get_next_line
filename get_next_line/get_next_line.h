/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 12:30:53 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/11/15 16:19:48 by jivan-de      ########   odam.nl         */
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
char				*ft_strchr(const chr *s, int c);

#endif
