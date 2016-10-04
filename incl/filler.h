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

typedef struct	s_filler
{
	t_board		*board;
	t_piece		*piece;
	char		player;
}				t_filer;

typedef struct	s_board
{
	char		**data;
	size_t		size_x;
	size_t		size_y;
}				t_board;

typedef struct	s_piece
{
	char		**data;
	size_t		size_x;
	size_t		size_y;
}				t_board;

#endif
