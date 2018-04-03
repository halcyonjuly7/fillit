/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:38:56 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/29 18:39:05 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piece.h"

t_coords	*new_coord(int row, int col)
{
	t_coords	*coord;

	coord = ft_memalloc(sizeof(t_coords));
	coord->row = row;
	coord->col = col;
	return (coord);
}

int			place_piece(t_coords **piece, t_map *board, t_piece_data p)
{
	t_coords	*cur_coord;
	int			coord_ind;

	coord_ind = 0;
	if (can_place(piece, board, p.row, p.col))
	{
		while (coord_ind < 4)
		{
			cur_coord = piece[coord_ind];
			board->board[p.row + cur_coord->row][p.col + cur_coord->col] =
					p.letter;
			coord_ind++;
		}
		return (1);
	}
	return (0);
}

int			can_place(t_coords **piece, t_map *board, int row, int col)
{
	int			coord_ind;
	int			checks;
	int			is_dot;
	t_coords	*cur_coord;

	checks = 0;
	coord_ind = 0;
	while (coord_ind < 4)
	{
		cur_coord = piece[coord_ind];
		is_dot = board->board[row + cur_coord->row][col + cur_coord->col] !=
				'.';
		if ((row + cur_coord->row) >= board->size
			|| (col + cur_coord->col >= board->size)
			|| (is_dot))
			return (0);
		checks++;
		coord_ind++;
	}
	return (1);
}

void		clear_piece(t_coords **piece, t_map *board, int row, int col)
{
	t_coords	*cur_coords;
	int			coord_ind;

	coord_ind = 0;
	while (coord_ind < 4)
	{
		cur_coords = piece[coord_ind];
		board->board[row + cur_coords->row][col + cur_coords->col] = '.';
		coord_ind++;
	}
}

