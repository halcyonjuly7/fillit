/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:05:11 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/24 17:12:54 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <stdlib.h>

void free_tetrimino(char **tetrimino)
{
	int index;

	index = 0;
	while (tetrimino[index])
		free(tetrimino[index++]);
	free(tetrimino);
}
