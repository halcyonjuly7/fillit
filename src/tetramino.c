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
#include <fcntl.h>
#include <stdlib.h>


t_list *get_coords(char **tetrimino)
{
	t_list *coord_list;
	t_point *coord;
	int row;
	int col;

	row = 0;
	coord_list = NULL;
	while(tetrimino[row])
	{
		col = 0;
		while(tetrimino[row][col])
		{
			if (tetrimino[row][col] == '#')
				ft_lstadd(&coord_list, ft_lstnew(new_coord(row, col), sizeof(t_coord)));
			col++;
		}
		row++;
	}
}


t_data get_map_data(char **tetrimino)
{
	int row;
	int col;
	t_data map_data;
	t_list coord_list;

	row = 0;
	col = 0;
	map_data = malloc(sizeof(t_data));
	coord_list = malloc(sizeof(t_list));
	while (tetrimino[row][col])
		col++;
	while (tetrimino[row])
		row++;
	t_data->cols = col;
	t_data->rows = row;
	t_data->checks = 0;
	return (t_data);
}

t_coord		*new_coord(int row, col)
{
	t_coord *coord;

	coord = ft_memmalloc(sizeof(t_coord));
	coord->row = row;
	coord->col = col;
	return (coord);
}

t_list			*extract_tetraminos(char **file_path)
{
	char		*buffer;
	char		**tetrimino;
	int			read_chars;

	t_list		*list;
	t_etmino	piece_data;
	t_data		map_data;
	buffer = ft_strnew(21);
	if (file_handle == -1)
		return (NULL);
	piece_data = malloc(sizeof(t_data));
	while ((read_chars = read(open(file_path, O_RDONLY), buffer, 21)) >= 20)
	{
		tetrimino = ft_strsplit(buffer);
		map_data = get_map_data(tetrimino);
		if (!validate_tetrimino(map_data, tetrimino))
			return (NULL);
		ft_lstadd(&list, ft_lstnew(normalize_coords(get_coords(tetrimino)), sizeof(t_list));
	}
	return (list);
}

