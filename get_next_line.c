/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:40:53 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/22 18:51:13 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_newline(char *s)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}

char	*read_and_append(int fd, char **result)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!find_newline(*result))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		*result = ft_strjoin(*result, buffer);
	}
	free(buffer);
	return (*result);
}

void	handle_remaining(char **result, char **remaining)
{
	char	*newline_pos;

	newline_pos = find_newline(*result);
	if (newline_pos)
	{
		*newline_pos = '\0';
		*remaining = ft_strdup(newline_pos + 1);
		*result = ft_strjoin(*result, "\n");
	}
}

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remaining)
		result = ft_strdup(remaining);
	else
		result = ft_strdup("");
	free(remaining);
	remaining = NULL;
	if (!read_and_append(fd, &result))
		return (NULL);
	handle_remaining(&result, &remaining);
	if (ft_strlen(result) == 0 && !remaining)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Abrir três arquivos diferentes (certifique-se de que esses arquivos existam)
    int fd1 = open("file1.txt", O_RDONLY);
    char *line1;

    for (int i = 0; i < 11; i++)
    {
        line1 = get_next_line(fd1);
        if (line1) {
            printf("fd1: %s", line1);
            free(line1);
        }
    }
    close(fd1);
    return 0;
}
