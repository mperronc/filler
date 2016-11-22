/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	get_board(char *line, t_filler *game)
{
	char	**dimensions;

	dimensions = ft_strsplit(line, ' ');
	game->board->size_x = ft_atoi(dimensions[2]);
	game->board->size_y = ft_atoi(dimensions[1]);
	if (game->board->data == NULL)
		game->board->data = allocate_board(game->board->size_x,
											game->board->size_y);
	update_board(game);
	free_data(dimensions);
}
