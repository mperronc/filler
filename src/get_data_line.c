/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

char	*get_header_line(char *line)
{
	char	c;
	char	buf[1024];
	int		i;

	if (line)
		free(line);
	i = 0;
	c = 0;
	read(0, &c, 1);
	while (i < 1024 && c != '\n')
	{
		buf[i++] = c;
		read(0, &c, 1);
	}
	buf[i] = 0;
	return (ft_strdup(buf));
}
