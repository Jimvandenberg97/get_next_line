/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jivan-de <jivan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 11:55:55 by jivan-de      #+#    #+#                 */
/*   Updated: 2019/11/28 17:34:55 by jivan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		status;

	if (argc <= 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	status = 1;
	while ((status = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("RETURN VALUE: [%d]  |%s\n", status, line);
	free(line);

	return (0);
}


int		main(void)
{
	int		fd1, fd2, fd3, fd4, fd5, fd6;
	char	*line;
	int		s1, s2, s3, s4, s5, s6;

	fd1 = open("../testfiles/test_nl.txt", O_RDONLY);
	fd2 = open("../testfiles/test_nonl.txt", O_RDONLY);
	fd3 = open("../testfiles/test_empty.txt", O_RDONLY);
	fd4 = open("../testfiles/holy_text.txt", O_RDONLY);
	fd5 = -1;
	fd6 = 100;
	s1 = s2 = s3 = s4 = s5 = s6 = 1;
	while (s1 > 0 || s2 > 0 || s3 > 0 || s4 > 0)
	{
		s1 = get_next_line(fd1, &line);
		printf("RETURN VALUE [fd1] : [%d]  |%s\n", s1, line);
		free(line);
		s2 = get_next_line(fd2, &line);
		printf("RETURN VALUE [fd2] : [%d]  |%s\n", s2, line);
		free(line);
		s3 = get_next_line(fd3, &line);
		printf("RETURN VALUE [fd3] : [%d]  |%s\n", s3, line);
		free(line);
		s4 = get_next_line(fd4, &line);
		printf("RETURN VALUE [fd4] : [%d]  |%s\n", s4, line);
		free(line);
	}
	printf("RETURN VALUE [fd1] : [%d]  |%s\n", s1, line);
	printf("RETURN VALUE [fd2] : [%d]  |%s\n", s2, line);
	printf("RETURN VALUE [fd3] : [%d]  |%s\n", s3, line);
	printf("RETURN VALUE [fd4] : [%d]  |%s\n", s4, line);
	s5 = get_next_line(fd5, &line);
	printf("RETURN VALUE [fd5] : [%d]\n", s5);
	s6 = get_next_line(fd6, &line);
	printf("RETURN VALUE [fd6] : [%d]\n", s6);
	return (0);
}
