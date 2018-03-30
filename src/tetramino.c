/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:32:13 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/27 16:38:57 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tetramino.h"
#include "validator.h"
#include "normalize.h"

t_coords		**get_coords(char **tetrimino)
{
	t_coords	**coord_list;
	int 		row;
	int 		col;
	int 		index;

	row = 0;
	index = 0;
	coord_list = malloc(sizeof(t_coords) * 4);
	while(tetrimino[row])
	{
		col = 0;
		while(tetrimino[row][col])
		{
			if (tetrimino[row][col] == '#')
			{
				coord_list[index] = new_coord(row, col);
				index++;
			}
			col++;
		}
		row++;
	}
	return (coord_list);
}


t_data			*get_map_data(char **tetrimino)
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

t_coords		*new_coord(int row, int col)
{
	t_coords	*coord;

	coord = ft_memalloc(sizeof(t_coords));
	coord->row = row;
	coord->col = col;
	return (coord);
}

t_list			*extract_tetraminos(int file_handle)
{
	char		*buffer;
	char		**tetrimino;
	t_coords	**coord_list;
	t_list		*list;
	t_data		*map_data;

	list = NULL;
	buffer = ft_strnew(21);
	while (read(file_handle, buffer, 21) >= 19)
	{
		tetrimino = ft_strsplit(buffer, '\n');
		map_data = get_map_data(tetrimino);
		if (!validate_tetramino(map_data, tetrimino))
			return (NULL);
		coord_list = normalize_coords(get_coords(tetrimino));
		ft_lstadd(&list, ft_lstnew(coord_list, sizeof(t_coords) * 4));
	}
	ft_memdel((void **)&buffer);
	ft_lstrev(&list);
	return (list);
}