/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	find_moves(t_moves *moves, t_filler *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->board->size_y - game->piece->size_y + 1)
	{
		j = 0;
		while (j < game->board->size_x - game->piece->size_x + 1)
		{
			if (try_move(game, j, i))
				add_move(moves, j, i);
			j++;
		}
		i++;
	}
}
