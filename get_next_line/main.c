/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 11:55:55 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/11/20 10:42:44 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int fd;
	char *line;
	int status;

	fd = open(argv[1], O_RDONLY);
	status = 1;
	while ((status = get_next_line(fd, &line)))
		printf("%s ", line);
	return (0);
}
