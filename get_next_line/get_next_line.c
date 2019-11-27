/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 12:29:44 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/11/27 15:11:56 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const	char *s)
{
	const char	*ptr;

	ptr = s;
	while (*s)
		s++;
	return (s - ptr);
}

char		*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)c == *s)
			return ((char*)s);
		s++;
	}
	if (*s == '\0' && (unsigned char)c == *s)
		return ((char*)s);
	return (NULL);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > slen)
		len = slen;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

static int	ft_read(const int fd, char *fd_store[fd], int x)
{
	char	*buf;
	char	*tmp;
	int		tmp_res;

	buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	tmp_res = read(fd, buf, BUFFER_SIZE);
	if (tmp_res >= 0 && x != -1)
		buf[tmp_res] = '\0';
	if (fd_store[fd] == NULL && tmp_res > 0 && x != -1)
		fd_store[fd] = ft_strdup(buf);
	else if (tmp_res > 0 && x != -1)
	{
		tmp = fd_store[fd];
		fd_store[fd] = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	if ((tmp_res == -1 && fd_store[fd]) || x == -1)
	{
		free(fd_store[fd]);
		fd_store[fd] = NULL;
	}
	return (tmp_res);
}

int			get_next_line(int fd, char **line)
{
	static char	*fd_store[INT_MAX];
	char		*ptr_nl;
	int			res;

	if (BUFFER_SIZE <= 0 || !line)
		return (-1);
	res = 1;
	while (!ft_strchr(fd_store[fd], '\n') && res > 0)
		res = ft_read(fd, fd_store, res);
	if (res > 0)
	{
		ptr_nl = ft_strchr(fd_store[fd], '\n');
		*line = ft_substr(fd_store[fd], 0, ptr_nl - fd_store[fd]);
		fd_store[fd] = ft_strdup(ptr_nl + 1);
		if (*line == NULL)
			res = ft_read(fd, fd_store, -1);
		return ((*line == NULL || res < 0) ? -1 : 1);
	}
	else if (res == 0)
	{
		*line = ft_strdup(fd_store[fd]);
		free(fd_store[fd]);
		fd_store[fd] = NULL;
	}
	return ((*line == NULL || res < 0) ? -1 : 0);
}
