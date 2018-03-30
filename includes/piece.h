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

#include "map.h"

int				place_piece(t_coords **, t_map *, int, int, char);
void 			clear_piece(t_coords **, t_map *, int, int);
int				can_place(t_coords **, t_map *, int, int);

# endif
