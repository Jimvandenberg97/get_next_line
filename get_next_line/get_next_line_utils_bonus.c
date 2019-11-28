/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 12:30:33 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/11/28 16:57:05 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (n == 0 || dst == src)
		return (dst);
	d = (char*)dst;
	s = (const char*)src;
	if (!d && !s)
		return (NULL);
	while (n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*mem;

	if (s1 == NULL)
		return (ft_strdup(""));
	len = ft_strlen(s1);
	mem = (char*)malloc(len + 1);
	if (!mem)
		return (NULL);
	ft_memcpy(mem, s1, len + 1);
	return (mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_1;
	size_t	len_2;

	if (!s1 || !s2)
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	str = malloc(len_1 + len_2 + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_1 + 1);
	ft_strlcat(str, s2, len_1 + len_2 + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;

	if (!dst || !src)
		return (0);
	slen = ft_strlen(src);
	if (slen + 1 < dstsize)
		ft_memcpy(dst, src, slen + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (slen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	if (dstsize < dlen)
		slen = slen + dstsize;
	else
		slen = slen + dlen;
	i = 0;
	while (src[i] != '\0' && dlen < dstsize - 1 && dst != src)
	{
		dst[dlen] = src[i];
		i++;
		dlen++;
	}
	dst[dlen] = '\0';
	return (slen);
}
