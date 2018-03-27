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

t_list *normalize_coords(t_list* coord_list)
{
	normalize_vertical(coord_list);
	normalize_horizontal(coord_list);
	return (coord_list);
}

void		normalize_vertical(t_list *coord_list)
{
	t_list	*current_item;
	t_coord	*current_coord;
	
	current_item = coord_list;
	while (1)
	{
		while (current_item)
		{
			current_coord = current_item->content;
			if (!(current_coord->row > 0))
				return;
			current_item = current_item->next;
		}
		current_item = coord_list;
		while (current_item)
		{
			current_coord = current_item->content;
			current_coord->row = row - 1;
			current_item = current_item->next;
		}
	}
}

void normalize_horizontal(t_list *coord_list)
{
	t_list	*current_item;
	t_coord	*current_coord;
	
	current_item = coord_list;
	while (1)
	{
		while (current_item)
		{
			current_coord = current_item->content;
			if (!(current_coord->col > 0))
				return;
			current_item = current_item->next;
		}
		current_item = coord_list;
		while (current_item)
		{
			current_coord = current_item->content;
			current_coord->col = col - 1;
			current_item = current_item->next;
		}
	
}