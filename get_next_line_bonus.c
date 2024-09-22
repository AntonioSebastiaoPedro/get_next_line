/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:40:53 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/22 21:19:44 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*find_newline(char *s)
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

static char	*read_and_append(int fd, char **result)
{
	char	*buffer[MAX_FD];
	ssize_t	bytes_read;

	buffer[fd] = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer[fd])
		return (NULL);
	while (!find_newline(*result))
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[fd][bytes_read] = '\0';
		*result = ft_strjoin(*result, buffer[fd]);
	}
	free(buffer[fd]);
	return (*result);
}

static void	handle_remaining(char **result, char **remaining)
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
	static char	*remaining[MAX_FD];
	char		*result;

	if (fd < 0 || fd > 1023 || MAX_FD > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remaining[fd])
		result = ft_strdup(remaining[fd]);
	else
		result = ft_strdup("");
	free(remaining[fd]);
	remaining[fd] = NULL;
	if (!read_and_append(fd, &result))
		return (NULL);
	handle_remaining(&result, &remaining[fd]);
	if (ft_strlen(result) == 0 && !remaining[fd])
	{
		free(result);
		return (NULL);
	}
	return (result);
}
