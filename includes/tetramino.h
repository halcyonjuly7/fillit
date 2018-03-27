/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetramino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:19:56 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/24 20:50:13 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAMINO_H

# define TERTRAMINO_H

#include "libft.h"

t_list extract_tetraminos(char **file_path);

typedef struct			s_etmino {
	char				**piece;
	struct s_etmino		*next;
}						t_etmino;

typedef struct	s_coords
{
	int			row;
	int			col;
}				t_coords;

# endif
