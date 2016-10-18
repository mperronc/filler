/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static int	get_offset(char *line)
{
	int offset;

	offset = 0;
	while (ft_isdigit(line[offset]))
		offset++;
	return (offset + 1);
}

void		update_board(t_filler *game)
{
	int		i;
	int		j;
	int		offset;
	char	*line;

	line = NULL;
	line = get_header_line(line);
	i = 0;
	while (i < game->board->size_y)
	{
		line = get_header_line(line);
		offset = get_offset(line);
		j = 0;
		while (j < game->board->size_x)
		{
			game->board->data[i][j] = line[j + offset];
			j++;
		}
		i++;
	}
	free(line);
}
