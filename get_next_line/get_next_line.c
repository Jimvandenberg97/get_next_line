/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 12:29:44 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/11/15 17:02:58 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static int		result;
	static int		i;
	char			*new
	char			*temp;

	if (!line || fd < 0)
		return (-1);
	buf = (char *)malloc(sizeof((char) * BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	result = read(fd, buf, BUFFER_SIZE);
	while(ft_strchr(buf, '\n') == NULL && *buf != EOF);
	{
		if (ft_strchr(buf, '\n') != NULL || *buf == EOF)
		{
			new = ft_strdup(buf);
			i = ft_strlen(buf OR new '?');
		}
		buf++;
	}
	temp = ft_strjoin(buf, new);
	free(new);
	if (result > 0)
		buf[result] = '\0';
	free(buf);
}
