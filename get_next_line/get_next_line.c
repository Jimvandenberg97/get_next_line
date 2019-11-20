/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 12:29:44 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/11/20 14:51:23 by jivan-de      ########   odam.nl         */
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

char	*readit(const int fd, char *str)
{
	char	buf[BUFFER_SIZE + 1];
	int		res;

	if (fd < 0 || read(fd, buf, 0) < 0 || BUFFER_SIZE < 1)
		return (0);
	if (str == NULL)
		str = ft_strdup("");
	while (!(ft_strchr(str, '\n')))
	{
		if ((res = read(fd, buf, BUFFER_SIZE)) < 0)
			return (0);
		buf[res] = '\0';
		str = ft_strjoin(str, buf);
		if (str[0] == '\0' || res == 0)
			break ;
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char *str;
	t_line		magic;

	if (!(str = readit(fd, str)) || !line)
		return (-1);
	if ((magic.temp = ft_strchr(str, '\n')) > 0)
	{
		magic.i = magic.temp - str;
		if (!(*line = ft_substr(str, 0, magic.i)))
			return (-1);
		str = ft_strdup(magic.temp + 1);
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(str)))
			return (-1);
		free(str);
		str = NULL;
		if (*line[0] == '\0')
			return (0);
		return (1);
	}
}
