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

#define B_POS game->board->data[y + i][x + j]
#define P_POS game->piece->data[i][j]
#define P_X game->piece->size_x
#define P_Y game->piece->size_y
#define B_X game->board->size_x
#define B_Y game->board->size_y

int		try_move(t_filler *game, int x, int y)
{
	int		i;
	int		j;
	int		player_symbols;

	i = 0;
	player_symbols = 0;
	while (i < P_Y)
	{
		j = 0;
		while (j < P_X)
		{
			if (i + y < 0 || x + j < 0 || i + y >= B_Y || x + j >= B_X)
			{
				if (P_POS == '*')
					return (0);
			}
			else if (ft_toupper(B_POS) == game->player && P_POS == '*')
				player_symbols++;
			else if (ft_toupper(B_POS) == game->enemy && P_POS == '*')
				return (0);
			j++;
		}
		i++;
	}
	return (player_symbols == 1 ? 1 : 0);
}
