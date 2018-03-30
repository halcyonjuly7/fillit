/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:57:51 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/27 16:38:44 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normalize.h"
#include "tetramino.h"

t_coords		**normalize_coords(t_coords **coord_list)
{
	normalize_horizontal(coord_list);
	normalize_vertical(coord_list);
	return (coord_list);
}

void			normalize_vertical(t_coords **coord_list)
{
	int			index;

	index = 0;
	while (1)
	{
		while (index < 4)
		{
			if (!(coord_list[index]->row > 0))
				return;
			index++;
		}
		index = 0;
		while (index < 4)
		{
			coord_list[index]->row = coord_list[index]->row - 1;
			index++;
		}
		index = 0;
	}
}

void			normalize_horizontal(t_coords **coord_list)
{
	int			index;

	index = 0;
	while (1)
	{
		while (index < 4)
		{
			if (!(coord_list[index]->col > 0))
				return;
			index++;
		}
		index = 0;
		while (index < 4)
		{
			coord_list[index]->col = coord_list[index]->col - 1;
			index++;
		}
		index = 0;
	}
}
