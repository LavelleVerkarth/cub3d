/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladin <vpaladin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:12:06 by vpaladin          #+#    #+#             */
/*   Updated: 2021/09/10 16:12:07 by vpaladin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_all	cub;

	if (argc != 2)
	{
		printf("Error: bad arguments\n");
		return (0);
	}
	cub.x = 0;
	if (parse_map(argv[1], &cub))
		return (1);
	init_mlx_minimap(&cub);
	init_player(&cub);
	init_mlx_big_map(&cub);
	init_texture(&cub);
	mlx_loop_hook(cub.win->mlx, (void *)all_do, &cub);
	mlx_hook(cub.win->win, 2, 1L << 0, keypress, &cub);
	mlx_hook(cub.win->win, 17, 1L << 2, close_all, &cub);
	mlx_loop(cub.win->mlx);
}
