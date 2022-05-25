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

char	*update_content(char *content)
{
	int		lenght;
	char	*updated;
	int		i;

	lenght = 0;
	while (content[lenght] && content[lenght] != '\n')
		lenght++;
	if (!content[lenght])
	{
		free(content);
		return (NULL);
	}
	updated = (char *)malloc(sizeof(char) * (ft_strlen(content) - lenght + 1));
	if (!updated)
		return (NULL);
	lenght++;
	i = 0;
	while (content[lenght])
		updated[i++] = content[lenght++];
	updated[i] = '\0';
	free(content);
	return (updated);
}

char	*ft_get_line(char *content)
{
	int		position;
	int		index;
	char	*new_line;

	position = 0;
	if (!content || !content[position])
		return (NULL);
	while (content[position] && content[position] != '\n')
		position++;
	new_line = (char *)malloc(sizeof(char) * position + 2);
	if (!new_line)
		return (NULL);
	index = 0;
	while (content[index] && content[index] != '\n')
	{
		new_line[index] = content[index];
		index++;
	}
	if (content[index] == '\n')
	{
		new_line[index] = content[index];
		index++;
	}
	new_line[index] = '\0';
	return (new_line);
}

char	*seek_new_line(char *content, int fd)
{
	char	*buff;
	int		read_bytes;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(content, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		content = ft_strjoin(content, buff);
	}
	free(buff);
	return (content);
}

char	*get_next_line(int fd)
{
	char		*new_line;
	static char	*content;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content = seek_new_line(content, fd);
	if (!content)
		return (NULL);
	new_line = ft_get_line(content);
	content = update_content(content);
	return (new_line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("teste.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }
