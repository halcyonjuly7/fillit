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
#include "solver.h"
#include "map.h"
#include <fcntl.h>

int				main(int argc, char **argv)
{
	t_list		*piece_list;
	int			file_handle;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	file_handle = open(argv[1], O_RDONLY);
	if (file_handle != -1)
	{
		if ((piece_list = extract_tetraminos(file_handle)) == NULL)
		{
			ft_putstr("error\n");
			close(file_handle);
			return (1);
		}
		solve(piece_list);
	}
	close(file_handle);
	return (0);
}
