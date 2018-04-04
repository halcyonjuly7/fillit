/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:32:56 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/29 18:38:38 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_PIECE_H
# define FILLIT_PIECE_H
# include "map.h"
# include "tetramino.h"

typedef struct	s_piece_data
{
	int			row;
	int			col;
	char		letter;
}				t_piece_data;

int				place_piece(t_coords **coords, t_map *map, t_piece_data p);
void			clear_piece(t_coords **coords, t_map *map, int row, int col);
int				can_place(t_coords **coords, t_map *map, int row, int col);
t_coords		*new_coord(int row, int col);

#endif
