/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:59:47 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/28 17:59:57 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "piece.h"

//char	**create_new_map(int size)
//{
//	int			row;
//	int			col;
//	char		**map;
//	char		*row;
//
//	row = 0;
//	map = (char **)malloc(sizeof(char *) * (size + 1));
//	while (row < size)
//	{
//		col = 0;
//		map[row] = ft_strnew((size_t)size);
//		while (col < size)
//		{
//			map[row][col] = '.';
//			col++;
//		}
//		row++;
//	}
//	return (map);
//}

char	**create_new_map(int size)
{
	int			row;
	int			col;
	char		**map;

	row = 0;
	map = (char **)malloc(sizeof(char *) * (size + 1));
	while (row < size)
	{
		col = 0;
		map[row] = ft_strnew((size_t)size);
		while (col < size)
		{
			map[row][col] = '.';
			col++;
		}
		row++;
	}
	map[row] = '\0';
	return (map);
}




void	print_map(t_map *board)
{
	int			row;
	int			col;

	row = 0;
	while (row < board->size)
	{
		col = 0;
		while (col < board->size)
			ft_putchar(board->board[row][col++]);
		ft_putchar('\n');
		row++;
	}
}

t_data	*get_map_data(char **tetrimino)
{
	int			row;
	int			col;
	t_data		*map_data;

	row = 0;
	col = 0;
	map_data = malloc(sizeof(t_data));
	while (tetrimino[row][col])
		col++;
	while (tetrimino[row])
		row++;
	map_data->cols = col;
	map_data->rows = row;
	map_data->checks = 0;
	return (map_data);
}
