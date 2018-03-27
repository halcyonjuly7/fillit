/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:11:32 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/27 15:51:40 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H

# define MAP_H

#include "tetrimino.h"
#include "libft.h"

typedef struct	s_data
{
	int 		rows;
	int 		cols;
	int			checks;
    t_list		*coord_list;	
}				t_data;

#endif
