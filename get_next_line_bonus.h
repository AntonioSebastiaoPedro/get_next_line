/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:40:55 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/22 20:09:41 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef MAX_FD
#  define MAX_FD 1023
# endif
# include <stdlib.h>
# include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *str);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);

#endif