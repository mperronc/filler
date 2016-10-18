/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
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
	char	*tmp;

	tmp = NULL;
	dimensions = ft_strsplit(line, ' ');
	game->piece->size_x = ft_atoi(dimensions[2]);
	game->piece->size_y = ft_atoi(dimensions[1]);
	game->piece->data = allocate_board(game->piece->size_x,
										game->piece->size_y);
	i = 0;
	while (i < game->piece->size_y)
	{
		tmp = get_header_line(tmp);
		j = 0;
		while (j < game->piece->size_x)
		{
			game->piece->data[i][j] = tmp[j];
			j++;
		}
		i++;
	}
	free(tmp);
	free_data(dimensions);
}
