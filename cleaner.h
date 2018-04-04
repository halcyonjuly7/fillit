/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:34:43 by hramirez          #+#    #+#             */
/*   Updated: 2018/04/02 18:34:50 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_CLEANER_H
# define FILLIT_CLEANER_H
# include <libft.h>
# include "map.h"

void	free_list(t_list *coord_list);
void	free_map(char **board);
void	free_tetrimino(char **tet);
void	free_coords(t_coords **coords);

#endif
