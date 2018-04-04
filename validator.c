/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:05:22 by hramirez          #+#    #+#             */
/*   Updated: 2018/04/03 18:44:28 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"
#define VAL_PMS int row;int col;int hash_count;

int		check_right(int cur_row, int cur_col, t_data *m_data, char **tet)
{
	if (cur_col + 1 == m_data->cols)
		return (0);
	return (tet[cur_row][cur_col + 1] == '#');
}

int		check_down(int cur_row, int cur_col, t_data *m_data, char **tet)
{
	if ((cur_row + 1) == m_data->rows)
		return (0);
	return (tet[cur_row + 1][cur_col] == '#');
}

void	check(int cur_row, int cur_col, t_data *map_data, char **tet)
{
	if (check_down(cur_row, cur_col, map_data, tet))
	{
		map_data->checks++;
	}
	if (check_right(cur_row, cur_col, map_data, tet))
	{
		map_data->checks++;
	}
}

int		validate_tetramino(t_data *map_data, char **tetrimino)
{
	VAL_PMS;
	row = 0;
	hash_count = 0;
	while (tetrimino[row])
	{
		if (ft_strlen(tetrimino[row]) != 4)
			return (0);
		col = 0;
		while (tetrimino[row][col])
		{
			if ((tetrimino[row][col] != '.') && (tetrimino[row][col] != '#'))
				return (0);
			if ((tetrimino[row][col]) == '#')
			{
				check(row, col, map_data, tetrimino);
				hash_count++;
			}
			col++;
		}
		row++;
	}
	return ((map_data->checks == 3 || map_data->checks == 4)
			&& hash_count == 4);
}
