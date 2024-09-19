/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:40:53 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/19 18:46:19 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

// static int	ft_wdlen(char const *s, char c)
// {
// 	int	count;

// 	count = 0;
// 	while (*s)
// 	{
// 		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
// 			count++;
// 		s++;
// 	}
// 	return (count);
// }

// static char	*ft_get_word(char const *s, int *i, char c)
// {
// 	int		word_len;
// 	char	*word;

// 	word_len = 0;
// 	while (s[*i + word_len] && s[*i + word_len] != c)
// 		word_len++;
// 	word = ft_substr(s, *i, word_len);
// 	*i += word_len;
// 	return (word);
// }

// static void	ft_freearray(char **array, int pos)
// {
// 	while (pos > 0)
// 		free(array[--pos]);
// 	free(array);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**tab;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	tab = (char **)malloc((ft_wdlen(s, c) + 1) * sizeof(char *));
// 	if (!s || !tab)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		if (s[i] != c)
// 		{
// 			tab[j] = ft_get_word(s, &i, c);
// 			if (!tab[j++])
// 			{
// 				ft_freearray(tab, j);
// 				return (NULL);
// 			}
// 		}
// 		else
// 			i++;
// 	}
// 	tab[j] = NULL;
// 	return (tab);
// }

char	*get_next_line(int fd)
{
	long	bytes_reads;
        char    *result;
	char	buffer[BUFFER_SIZE];
        
        bytes_reads = read(fd, &buffer, BUFFER_SIZE);
        if (bytes_reads < 0)
                return (NULL);
        while ()
        result = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
        strncpy(result, buffer, BUFFER_SIZE);
        return(result);
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
	printf("%s\n", get_next_line(fd));
        printf("%s\n", get_next_line(fd));
        close(fd);
	return (0);
}
