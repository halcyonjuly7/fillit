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

#include "solver.h"
#include "piece.h"

void solve(t_list *coord_list)
{
	t_map *map;
	char letter;

	letter = 'A';
	map = malloc(sizeof(t_map));
	map->size = 2;
	map->board = create_new_map(15);
	while (!solve_fillit(map, coord_list, letter))
		map->size = map->size + 1;
	print_map(map);

}

int solve_fillit(t_map *board, t_list *coords, char letter)
{
	int row;
	int col;

	if (coords == NULL)
		return (1);
	row = 0;
	while (row < board->size)
	{
		col = 0;
		while (col < board->size)
		{
			if (place_piece(coords->content, board, row, col, letter))
			{
				if (solve_fillit(board, coords->next, letter+1))
					return (1);
				else
					clear_piece(coords->content, board, row, col);
			}
			col++;
		}
		row++;
	}
	return (0);
}
