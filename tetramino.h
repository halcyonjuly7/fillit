/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:19:56 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/24 20:50:13 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAMINO_H
# define TETRAMINO_H
# include "libft.h"

typedef struct			s_etmino {
	char				**piece;
	struct s_etmino		*next;
}						t_etmino;

typedef struct			s_coords
{
	int					row;
	int					col;
}						t_coords;

typedef struct			s_data
{
	int					rows;
	int					cols;
	int					checks;
}						t_data;

t_coords				*new_coord(int row, int col);
t_list					*extract_tetraminos(int fd);
t_coords				**get_coords(char **tet);
int						validate_buffer(char *buffer);

#endif
