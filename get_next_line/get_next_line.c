/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 12:29:44 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/11/14 16:35:07 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int				result;
	static char		ln[BUFFER_SIZE + 1];
	char			*new;

	if (!line || fd < 0)
		return (-1);
	while (result = read(fd, ln, BUFFER_SIZE) > 0 ) 
	{
		
	}
}
