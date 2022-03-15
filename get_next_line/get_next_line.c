/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansilva- <ansilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:20:34 by ansilva-          #+#    #+#             */
/*   Updated: 2022/03/14 15:00:41 by ansilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	b;

	b = c;
	i = 0;
	while (s && s[i] && (s[i] != b))
		i++;
	if (s[i] == b)
		return ((char *)s + i);
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	static ssize_t	read_bytes;
	static char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	line = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, line, BUFFER_SIZE);
	}
	line[read_bytes] = '\0';
	return (line);
}

int	main()
{
	int		fd;
	char	*line1;
	char	*line2;
	char	*line3;

	fd = open("teste.txt", O_RDONLY);
	line1 = get_next_line(fd);
	line2 = get_next_line(fd);
	line3 = get_next_line(fd);
	printf("linha 1: %s\nlinha 2: %s\nlinha 3: %s\n", line1, line2, line3);
	close(fd);
	return (0);
}
