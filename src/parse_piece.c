/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	parse_piece(char *line, t_filler *game)
{
	int		i;
	int		j;
	char	**dimensions;

	dimensions = ft_strsplit(line, ' ');
	game->piece->size_x = ft_atoi(dimensions[1]);
	game->piece->size_y = ft_atoi(dimensions[2]);
	game->piece->data = allocate_board(game->piece->size_x,
										game->piece->size_y);
	i = 0;
	while (i < game->piece->size_y)
	{
		get_next_line(3, &line);
		j = 0;
		while (j < game->piece->size_x)
		{
			game->piece->data[i][j] = line[j];
			j++;
		}
		i++;
	}
	free_data(dimensions);
}
