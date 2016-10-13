/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	play_piece(char *line, t_filler *game)
{
	t_moves		*moves;

	moves = init_moves(10000);
	parse_piece(line, game);
	find_moves(moves, game);
	if (moves->cur_moves > 0)
		choose_move(moves, game);
	else
	{
		ft_printf("%d %d\n", game->board->size_y, game->board->size_x);
		game->error = 1;
	}
	free_moves(moves);
	free_data(game->piece->data);
}
