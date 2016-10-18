/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_moves_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		zeroes(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
}

t_moves		*init_moves(int size)
{
	t_moves	*moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	moves->cur_moves = 0;
	moves->max_moves = size;
	moves->x = (int *)malloc(sizeof(int) * size);
	zeroes(moves->x, size);
	moves->y = (int *)malloc(sizeof(int) * size);
	zeroes(moves->y, size);
	return (moves);
}

void		free_moves(t_moves *moves)
{
	free(moves->x);
	moves->x = NULL;
	free(moves->y);
	moves->y = NULL;
	free(moves);
	moves = NULL;
}

void		extend_moves(t_moves *moves)
{
	int		*tmpx;
	int		*tmpy;
	int		i;

	tmpx = moves->x;
	tmpy = moves->y;
	moves->x = (int *)malloc(sizeof(int) * moves->max_moves + MOVES_STORAGE);
	moves->y = (int *)malloc(sizeof(int) * moves->max_moves + MOVES_STORAGE);
	i = 0;
	while (i < moves->max_moves)
	{
		moves->x[i] = tmpx[i];
		moves->y[i] = tmpy[i];
		i++;
	}
	zeroes(&(moves->x[i]), MOVES_STORAGE);
	zeroes(&(moves->y[i]), MOVES_STORAGE);
	free(tmpx);
	free(tmpy);
	moves->max_moves += MOVES_STORAGE;
}

void		add_move(t_moves *moves, int x, int y)
{
	if (moves->cur_moves >= moves->max_moves)
		extend_moves(moves);
	moves->x[moves->cur_moves] = x;
	moves->y[moves->cur_moves] = y;
	moves->cur_moves += 1;
}
