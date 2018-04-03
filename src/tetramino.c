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

#include <cleaner.h>
#include "libft.h"
#include "tetramino.h"
#include "validator.h"
#include "normalize.h"
#define X_PMS char* buffer;char** tet;t_coords **coord_list
#define X_PMS2 t_list* list;t_data* m_d;int n;int prev_read;

t_coords	**get_coords(char **tetrimino)
{
	t_coords	**coord_list;
	int			row;
	int			col;
	int			index;

	row = 0;
	index = 0;
	coord_list = malloc(sizeof(t_coords) * 4);
	while (tetrimino[row])
	{
		col = 0;
		while (tetrimino[row][col])
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

int			validate_buffer(char *buffer)
{
	int		index;
	int		newline_count;
	char	current_char;

	index = 0;
	newline_count = 0;
	if ((buffer[19] == '\n' && !(buffer[20] == '\n' || buffer[20] == '\0'))
		|| !(buffer[0] == '.' || buffer[0] == '#'))
		return (0);
	while (buffer[index])
	{
		current_char = buffer[index];
		if (current_char == '.' || current_char == '#' || current_char == '\n')
		{
			if (current_char == '\n')
				newline_count++;
			index++;
		}
		else
			return (0);
	}
	return ((newline_count == 5 || newline_count == 4));
}

t_list		*extract_tetraminos(int file_handle)
{
	X_PMS;
	X_PMS2;
	list = NULL;
	buffer = ft_strnew(21);
	while ((n = read(file_handle, buffer, 21)) >= 20)
	{
		prev_read = n;
		if (!validate_buffer(buffer))
			return (NULL);
		tet = ft_strsplit(buffer, '\n');
		m_d = get_map_data(tet);
		if (m_d->rows != 4 || m_d->cols != 4 || !validate_tetramino(m_d, tet))
		{
			free(m_d);
			return (NULL);
		}
		coord_list = normalize_coords(get_coords(tet));
		ft_lstadd(&list, ft_lstnew(coord_list, sizeof(t_coords) * 4));
		ft_strclr(buffer);
		free_tetrimino(tet);

	}
	ft_memdel((void **)&buffer);
	if (prev_read != 20)
		return (NULL);
	ft_lstrev(&list);
	return (list);
}
