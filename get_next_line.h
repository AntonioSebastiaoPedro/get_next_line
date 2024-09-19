/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:40:55 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/19 17:18:04 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 42
#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putstr_fd(char *s, int fd);

#endif