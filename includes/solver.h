/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:11:53 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/27 18:13:32 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

#include "map.h"

void	solve(t_list *coord_list);
int		solve_fillit(t_map *board, t_list *coords, char letter);

#endif
