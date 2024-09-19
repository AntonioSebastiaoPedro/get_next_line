/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:59:43 by ansebast          #+#    #+#             */
/*   Updated: 2024/09/19 18:43:38 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	while (*s != '\0')
		write(fd, s++, 1);
}

