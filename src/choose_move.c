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

#define SQRT 1.4142
#define MIDDLE_X game->board->size_x / 2
#define MIDDLE_Y game->board->size_y / 2

static double	calc_dist(int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int min;
	int max;

	dx = ft_abs(x2 - x1);
	dy = ft_abs(y2 - y1);
	min = ft_min2(dx, dy);
	max = ft_max2(dx, dy);
	return (SQRT * min + max - min);
}

void			choose_move(t_moves *moves, t_filler *game)
{
	int		i;
	double	distance;
	double	min_distance;
	int		imove;

	i = 0;
	imove = 0;
	min_distance = game->board->size_x * game->board->size_y;
	while (i < moves->cur_moves)
	{
		distance = calc_dist(moves->x[i], moves->y[i], MIDDLE_X, MIDDLE_Y);
		if (distance < min_distance)
		{
			min_distance = distance;
			imove = i;
		}
		i++;
	}
	ft_printf("%d %d\n", moves->y[imove], moves->x[imove]);
}
