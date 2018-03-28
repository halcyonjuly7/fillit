/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:47:13 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/27 16:22:34 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMALIZE_H

# define NORMALIZE_H

#include "libft.h"
#include "tetramino.h"

//t_list	*normalize_coords(t_list *coord_list);
t_coords	**normalize_coords(t_coords **coord_list);
void		normalize_vertical(t_coords **coord_list);
void		normalize_horizontal(t_coords **coord_list);
//void	normalize_vertical(t_list *coord_list);
//void	normalize_horizontal(t_list *coord_list);

#endif


