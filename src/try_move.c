/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int		try_move(t_filler *game, int x, int y)
{
	int		i;
	int		j;
	int		invalid;
	int		player_symbols;

	i = 0;
	player_symbols = 0;
	invalid = 0;
	while (!invalid && i < game->piece->size_y)
	{
		j = 0;
		while (!invalid && j < game->piece->size_x)
		{
			if (i + y < 0 || x + j < 0 || i + y >= game->board->size_y || x + j >= game->board->size_x)
			{
				if (game->piece->data[i][j] != '.')
					invalid = 1;
			}
			else if (ft_toupper(game->board->data[y + i][x + j]) == game->player
				&& game->piece->data[i][j] == '*')
				player_symbols++;
			else if (ft_toupper(game->board->data[y + i][x + j]) == game->enemy
						&& game->piece->data[i][j] == '*')
				invalid = 1;
			j++;
		}
		i++;
	}
	return ((!invalid && player_symbols == 1) ? 1 : 0);
}
