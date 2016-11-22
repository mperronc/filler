/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static void	count_symbols(int **sectors, t_filler *game)
{
	int		i;
	int		j;
	int		x;

	x = 0;
	i = 0;
	while (i < game->board->size_y)
	{
		j = 0;
		while (j < game->board->size_x)
		{
			x = (j / (game->board->size_x / 5)) + (5 * (i / (game->board->size_y / 5)));
			x = x % 25;
			if (game->board->data[i][j] == game->player)
				(*sectors)[x] -= 3;
			else if (game->board->data[i][j] == game->enemy)
				(*sectors)[x] += 1;
			else if (game->board->data[i][j] == '.')
				(*sectors)[x] += 3;
			j++;
		}
		i++;
	}
}

static int get_max(int *sectors)
{
	int max;
	int i;

	max = 0;
	i = 0;
	while (i < 25)
	{
		if (sectors[i] > sectors[max])
			max = i;
		i++;
	}
	return (max);
}

static void	choose_sector(int *sectors, t_filler *game)
{
	int		x;

	x = get_max(sectors);
	game->target_x = (x % 5) * game->board->size_x / 5 + game->board->size_x / 10;
	game->target_y = (x / 5) * game->board->size_y / 5 + game->board->size_y / 10;
}

void	get_target(t_filler *game)
{
	int		*sectors;
	int		i;

	sectors = (int *)malloc(sizeof(int) * 25);
	i = 0;
	while (i < 25)
		sectors[i++] = 0;
	count_symbols(&sectors, game);
	choose_sector(sectors, game);
	free(sectors);
}
