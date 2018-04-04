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
# include "libft.h"
# include "tetramino.h"

typedef struct	s_map
{
	int			size;
	char		**board;
}				t_map;

char			**create_new_map(int size);
void			print_map(t_map *map);
t_data			*get_map_data(char **tet);

#endif
