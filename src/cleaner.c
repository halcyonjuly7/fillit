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

void		free_list(t_list* coord_list)
{
	t_list *current;
	t_list * next;
	int index;
	t_coords** content;

	current = coord_list;
	while (current)
	{
		index = 0;
		content = current->content;
		while (index < 4)
			free(content[index++]);
		next = current->next;
		free(current);
		current = next;
	}
}

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

void free_tetrimino(char** tet)
{
	int index;

	index = 0;
	while (tet[index])
	{
		free(tet[index]);
		index++;
	}
	free(tet);
}