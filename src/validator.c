/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:05:22 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/24 17:33:36 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"



int check_right(int cur_row, int cur_col, t_data *m_data, char **tet)
{
	if (cur_col + 1 == m_data->cols)
		return (-1);
	return (tet[cur_row][cur_col] == '#');
}

int check_down(int cur_row, int cur_col, t_data *m_data, char **tet)
{
	if ((cur_row + 1) == m_data->rows)
		return (-1);
	return (tet[cur_row + 1][cur_col] == '#');
}

int check_left(int cur_row, int cur_col, char **tet)
{

	if ((cur_col - 1) < 0)
		return (-1);
	return (tet[cur_row - 1][cur_col] == '#');
}


void check(int cur_row, int cur_col, t_data *map_data, char **tet)
{
	if (check_down(cur_row, cur_col, map_data, tet))
	{
		map_data->checks++;
		return;
	}
	if (check_right(cur_row, cur_col, map_data, tet))
	{
		map_data->checks++;
		return;
	}

	if (check_left(cur_row, cur_col, tet))
	{
		map_data->checks++;
		return;
	}
}

int validate_tetramino(t_data *map_data, char **tetrimino)
{
	int row;
	int col;

	row = 0;
	while (tetrimino[row])
	{
		col = 0;
		while (tetrimino[row][col])
		{
			if ((tetrimino[row][col]) == '#')
				check(row, col, map_data, tetrimino);
			col++;
		}
		row++;
	}
	return (map_data->checks == 4);
}
