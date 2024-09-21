/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:40:55 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/21 14:52:55 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif
#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);

#endif