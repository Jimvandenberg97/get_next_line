/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 12:29:44 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/11/19 16:58:43 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	new = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char			*ft_strdup(const char *s1)
{
	char	*mem;
	size_t	len;

	len = ft_strlen(s1);
	mem = malloc(sizeof(char) * len + 1);
	if (!mem)
		return (NULL);
	ft_strlcpy(mem, s1, len + 1);
	return (mem);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdest;
	const char		*psource;

	pdest = dst;
	psource = src;
	if (pdest == NULL && psource == NULL)
		return (NULL);
	while (n > 0)
	{
		*pdest = *psource;
		n--;
		pdest++;
		psource++;
	}
	return (dst);
}

static int	ft_readbuf(int fd, char **ptr)
{
	char	*buf;
	int		ret;
	char	*new;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	ret = read(fd, &buf[fd], BUFFER_SIZE);
	if (ret > 0)
	{
		new = ft_strjoin(*ptr, &buf[fd]);
		free(*ptr);
		*ptr = new;
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char		*fd_store[INT_MAX];
	int				result;
	char			*endl;

	if (!line)
		return (-1);
	endl = ft_strchr(fd_store[fd], '\n');
	while (endl == NULL)
	{
		result = ft_readbuf(fd, &fd_store[fd]);
		if (result == 0)
		{
			endl = ft_strchr(fd_store[fd], '\0');
			if (endl == fd_store[fd])
				return (0);
		}
		else if (result < 0)
			return (-1);
		endl = ft_strchr(fd_store[fd], '\0');
		if (endl == NULL)
			endl = ft_strchr(fd_store[fd], '\n');
	}
	*line = ft_substr(fd_store[fd], 0, (endl - fd_store[fd]));
	if (*line == NULL)
		return (-1);
	endl = ft_strdup(endl + 1);
	free(fd_store[fd]);
	fd_store[fd] = endl;
	return (1);
}
