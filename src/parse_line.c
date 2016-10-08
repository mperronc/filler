/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	parse_line(char *line, t_filler *game)
{
	if (ft_strstr(line, "$$$"))
		get_player_symbols(line, game);
	else if (ft_strstr(line, "Plateau"))
		get_board(line, game);
	else if (ft_strstr(line, "Piece"))
		play_piece(line, game);
	else
		return ;
}
