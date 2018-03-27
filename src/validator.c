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
#include "map.h"

int check_right(int cur_row, int cur_col, t_data m_data, char **tet)
{
	if (cur_col + 1 == m_data.col)
		return (-1);
	return (tet[cur_row][cur_col] == '#');
}
int check_left(int cur_row, int cur_col, char **tet)
{
	if ((cur_col - 1) < 0 )
		return (-1);
	return (tet[cur_row][cur_col - 1] == '#')
}
int check_up(int cur_row, int cur_col, t_data m_data, char **tet)
{
	if ((cur_row - 1) < 0)
		return (-1);
	return (tet[cur_row - 1][cur_col] == '#');
}
int check_down(int cur_row, int cur_col, t_data m_data, char **tet)
{
	if ((cur_row + 1) == m_data.row)
		return (-1);
	return (tet[cur_row + 1][cur_col] == '#');
}

int validate_tetrimino(t_data *map_data, char *tetrimino)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (tetrimino[row])
	{
		col = 0;
		while (tetrimino[row][col])
		{
			if ((tetrimino[row][col]) == '#')
			{
				if (check_down(row, col, map_data, tetrimino))
				{
					map_data->checks++;
					break;
				}
				if (check_right(row, col, map_data, tetrimino))
				{
					map_data->checks++;
					break;
				}
			}
			col++;
		}
		row++;
	}
	return (map_data->checks == 4); 
}
