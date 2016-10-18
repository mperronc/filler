/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

#define BUF_SIZE 10000

char	*get_header_line(char *line)
{
	char	c;
	char	buf[BUF_SIZE];
	int		i;

	if (line)
		free(line);
	i = 0;
	c = 0;
	while (i < BUF_SIZE && c != '\n')
	{
		read(0, &c, 1);
		buf[i++] = c;
	}
	buf[--i] = 0;
	return (ft_strdup(buf));
}
