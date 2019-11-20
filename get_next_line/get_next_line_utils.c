/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 12:30:33 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/11/19 17:11:17 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c && *s != '\0')
		s++;
	if (*s == (unsigned char)c)
		return ((char*)s);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		count;
	int		string1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	string1 = ft_strlen(s1);
	count = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(count + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, string1 + 1);
	ft_strlcat(new, s2, count + 1);
	return (new);
}

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srclen);
	if (dstsize < dstlen)
		srclen = srclen + dstsize;
	else
		srclen = srclen + dstlen;
	while (src[i] != '\0' && dstlen < dstsize - 1 && dst != src)
	{
		dst[dstlen] = src[i];
		i++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (srclen);
}

size_t	ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	len;

	len = 0;
	if (dst == NULL || src == NULL)
		return (len);
	len = ft_strlen(src);
	if (len + 1 < dstsize)
		ft_memcpy(dst, src, len + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}
