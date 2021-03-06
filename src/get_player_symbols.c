/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_symbols.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	get_player_symbols(char *line, t_filler *game)
{
	if (ft_strstr(line, "exec p1"))
	{
		game->player = 'O';
		game->enemy = 'X';
	}
	else if (ft_strstr(line, "exec p2"))
	{
		game->player = 'X';
		game->enemy = 'O';
	}
	else
		game->error = 1;
}
