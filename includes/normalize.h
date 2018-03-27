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

t_list	*normalize_coords(char * tetrimino);
void	normalize_left(t_list *coord_list);
void	normalize_right(t_list *coord_list);


