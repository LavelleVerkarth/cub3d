/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladin <vpaladin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:11:48 by vpaladin          #+#    #+#             */
/*   Updated: 2021/09/10 16:11:50 by vpaladin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_big_map(t_all *cub)
{
	t_win	*init_img;

	cub->big_win = malloc(sizeof(t_win));
	if (!cub->big_win)
		error("Error malloc!\n");
	init_img = cub->big_win;
	init_img->mlx = cub->win->mlx;
	init_img->win = cub->win->win;
	init_img->img = mlx_new_image(init_img->mlx, 1920, 1080);
	init_img->addr = mlx_get_data_addr(init_img->img,
			&init_img->bpp, &init_img->line_l, &init_img->en);
}

void	init_mlx_minimap(t_all *cub)
{
	t_win	*data;

	cub->win = malloc(sizeof(t_win));
	if (!cub->win)
		error("Error malloc!\n");
	data = cub->win;
	data->mlx = NULL;
	data->win = NULL;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGTH, "Cub3d");
	data->img = mlx_new_image(data->mlx, 180, 180);
	data->addr = mlx_get_data_addr(data->img,
			&data->bpp, &data->line_l, &data->en);
}
