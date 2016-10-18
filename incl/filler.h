/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperronc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:58:48 by mperronc          #+#    #+#             */
/*   Updated: 2016/09/05 11:58:45 by mperronc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/incl/libft.h"
# include "../libft/incl/ft_printf.h"
# include <stdio.h>

# define MOVES_STORAGE 10000

typedef struct	s_board
{
	char		**data;
	int			size_x;
	int			size_y;
}				t_board;

typedef struct	s_piece
{
	char		**data;
	int			size_x;
	int			size_y;
}				t_piece;

typedef struct	s_filler
{
	t_board		*board;
	t_piece		*piece;
	char		player;
	char		enemy;
	int			error;
}				t_filler;

typedef struct	s_moves
{
	int			cur_moves;
	int			max_moves;
	int			*x;
	int			*y;
}				t_moves;

char		**allocate_board(int size_x, int size_y);
void		add_move(t_moves *moves, int x, int y);
void		choose_move(t_moves *moves, t_filler *game);
void		extend_moves(t_moves *moves);
void		find_moves(t_moves *moves, t_filler *game);
void		free_data(char **data);
void		free_game(t_filler *game);
void		free_moves(t_moves *moves);
void		get_board(char *line, t_filler *game);
void		get_player_symbols(char *line, t_filler *game);
char		*get_data_line(char *line, int size);
char		*get_header_line(char *line);
t_filler	*init_game();
t_moves		*init_moves(int size);
void		make_move_naive(t_filler *game);
void		parse_line(char *line, t_filler *game);
void		parse_piece(char *line, t_filler *game);
void		play_piece(char *line, t_filler *game);
void		print_board(char **data, int size_y);
int			try_move(t_filler *game, int x, int y);
void		update_board(t_filler *game);

#endif
