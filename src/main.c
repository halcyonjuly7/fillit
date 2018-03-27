/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:24:15 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/24 17:42:20 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include "solver.h"
#include "tetrimino.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	int file_desc;
	t_list piece_list;
	
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	
	if ((piece_list = extract_tetrimino(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
	   	return (1);
	}
	
	return (0);
}
