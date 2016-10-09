/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static void find_enemy(int (*enemy_pos)[2], t_filler *game)
{
	int		i;
	int		j;
	int		found;

	found = 0;
	i = 0;
	while (!found && i < game->board->size_y)
	{
		j = 0;
		while (!found && j < game->board->size_x)
		{
			if (game->board->data[i][j] == ft_tolower(game->enemy))
			{
				(*enemy_pos)[0] = j;
				(*enemy_pos)[1] = i;
				found = 1;
			}
			j++;
		}
		i++;
	}
}

static double calc_dist(int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int min;
	int max;

	dx = ft_abs(x2 - x1);
	dy = ft_abs(y2 - y1);
	min = ft_min2(dx, dy);
	max = ft_max2(dx, dy);
	return (1.414 * min + max - min);
}

void	choose_move(t_moves *moves, t_filler *game)
{
	int		enemy_pos[2];
	int		i;
	double  distance;
	double	min_distance;
	int		imove;

	find_enemy(&enemy_pos, game);
	//ft_printf("enemy position set at %d %d\n", enemy_pos[1], enemy_pos[0]);
	i = 0;
	imove = 0;
	min_distance = game->board->size_x * game->board->size_y;
	//printf("min_distance set at %f\n", min_distance);
	while (i < moves->cur_moves)
	{
		distance = calc_dist(moves->x[i], moves->y[i], enemy_pos[0], enemy_pos[1]);
		//printf("distance from %d %d to %d %d : %f\n", moves->y[i], moves->x[i], enemy_pos[1], enemy_pos[0], distance);
		if (distance < min_distance)
		{
			min_distance = distance;
			imove = i;
		}
		i++;
	}
	ft_printf("%d %d\n", moves->y[imove], moves->x[imove]);
}
