/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:40:53 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/21 15:45:04 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

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

char	*get_next_line(int fd)
{
	static char	*remaining = NULL;
	char		*buffer;
	char		*newline_pos;
	char		*result;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
        if (remaining)
                result = ft_strjoin(ft_strdup(""), remaining);
        else
                result = ft_strjoin(ft_strdup(""), "");
	free(remaining);
	remaining = NULL;

	while (!find_newline(result))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(result);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break;
		result = ft_strjoin(result, buffer);
	}
        newline_pos = find_newline(result);
	if (newline_pos)
	{
		*newline_pos = '\0';
		remaining = ft_strdup(newline_pos + 1);
	}
	free(buffer);
	if (ft_strlen(result) == 0 && bytes_read == 0)
	{
		free(result);
		return (NULL);
	}
        if (newline_pos)
                result = ft_strjoin(result, "\n");
	return (result);
}

int	main(int ac, char *av[])
{
        int     fd;

	(void)ac;
	(void)av;
        fd = open("file.txt", O_RDONLY);
        if (fd == -1)
        {
                close(fd);
                exit(255);
        }
        char *str = get_next_line(fd);
	printf("%s", str);
        free(str);
        close(fd);
	return (0);
}
