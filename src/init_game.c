/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

t_filler	*init_game(void)
{
	t_filler	*game;

	game = (t_filler *)malloc(sizeof(t_filler));
	game->board = (t_board *)malloc(sizeof(t_board));
	game->board->data = NULL;
	game->board->size_x = 0;
	game->board->size_y = 0;
	game->piece = (t_piece *)malloc(sizeof(t_piece));
	game->piece->data = NULL;
	game->piece->size_x = 0;
	game->piece->size_y = 0;
	game->player = 0;
	game->enemy = 0;
	game->target_x = -1;
	game->target_y = -1;
	game->error = 0;
	return (game);
}
