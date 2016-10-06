/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int main(void)
{
	t_filler	*game;
	char		*line;

	game = NULL;
	game = init_game(game);

	while (get_next_line(0, &line) > 0)
	{
		parse_line(line, game);
	}
	ft_printf("Player symbol is : %c\n", game->player);
	ft_printf("Board state is :\n");
	print_board(game->board->data, game->board->size_y);
	ft_printf("Piece I got is :\n");
	print_board(game->piece->data, game->piece->size_y);
	free_game(game);
	free(line);
	return (0);
}
