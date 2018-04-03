/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:31:30 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/29 18:31:53 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cleaner.h>
#include "solver.h"
#include "piece.h"

void	solve(t_list *coord_list)
{
	t_map	*map;
	char	letter;

	letter = 'A';
	map = malloc(sizeof(t_map));
	map->size = 2;
	map->board = create_new_map(15);
	while (!solve_fillit(map, coord_list, letter))
		map->size = map->size + 1;
	print_map(map);
	free_map(map);
	free_list(coord_list);
}

int		solve_fillit(t_map *board, t_list *coords, char letter)
{
	t_piece_data piece_data;

	piece_data.letter = letter;
	if (coords == NULL)
		return (1);
	piece_data.row = 0;
	while (piece_data.row < board->size)
	{
		piece_data.col = 0;
		while (piece_data.col < board->size)
		{
			if (place_piece(coords->content, board, piece_data))
			{
				if (solve_fillit(board, coords->next, letter + 1))
					return (1);
				clear_piece(coords->content, board, piece_data.row,
							piece_data.col);
			}
			piece_data.col++;
		}
		piece_data.row++;
	}
	return (0);
}