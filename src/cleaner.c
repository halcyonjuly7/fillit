/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:34:22 by hramirez          #+#    #+#             */
/*   Updated: 2018/04/02 18:34:27 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleaner.h"


void	free_map(t_map *board)
{
	int			row;

	row = 0;
	while (row < board->size)
	{
		free(board->board[row]);
		row++;
	}
	free(board);
}

void	free_tetrimino(char** tet)
{
	int			index;

	index = 0;
	while (tet[index])
	{
		free(tet[index]);
		index++;
	}
	free(tet);
}

void	free_coords(t_coords** coords)
{
	int index;

	index = 0;
	while (index < 4)
		free(coords[index++]);
	free(coords);
}

void	free_list(t_list* coord_list)
{
	t_list*		current;
	t_list*		next;

	current = coord_list;
	while (current)
	{
		free_coords(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
