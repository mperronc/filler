/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move_naive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	make_move_naive(t_filler *game)
{
	int		move_found;
	int		i;
	int		j;

	move_found = 0;
	i = 0;
	while (!move_found && i < game->board->size_y - game->piece->size_y + 1)
	{
		j = 0;
		while (!move_found && j < game->board->size_x - game->piece->size_x + 1)
		{
			move_found = try_move(game, j, i);
			j++;
		}
		i++;
	}
	if (!move_found)
		ft_putstr("-1\n");
}
