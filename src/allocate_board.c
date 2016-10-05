/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	allocate_board(int size_x, int size_y)
{
	char	**board;
	int		i;

	board = (char **)malloc(sizeof(char *) * (size_y + 1));
	i = 0;
	while (i < size_y)
		board[i] = ft_strnew(size_x);
	board[i] = 0;
	return (board);
}
