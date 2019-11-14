/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 12:30:33 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/11/14 15:32:22 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c && *s != '\0')
		s++;
	if (*s == (unsigned char)c)
		return ((char*)s);
	else
		return (NULL);
}


