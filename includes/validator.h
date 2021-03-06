/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:38:23 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/23 19:48:55 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H
# include "map.h"

int		check_right(int cur_row, int cur_col, t_data *m_data, char **tet);
int		check_down(int cur_row, int cur_col, t_data *m_data, char **tet);
void	check(int cur_row, int cur_col, t_data *map_data, char **tet);
int		validate_tetramino(t_data *map_data, char **tetrimino);

#endif
