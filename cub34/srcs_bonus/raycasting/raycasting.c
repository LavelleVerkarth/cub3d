/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 12:47:02 by lverkart          #+#    #+#             */
/*   Updated: 2021/09/05 12:47:04 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_texture(t_all *cub, t_lodev *all, int i, int x)
{
	int	color;
	int	texY;

	while (i < all->drawEnd)
	{
		texY = (int) all->texPos & (TEX_HEIGHT - 1);
		all->texPos += all->step;
		if (all->side == 1)
		{
			if (all->stepY == -1)
				color = cub->win->color.west[all->texX][texY];
			else
				color = cub->win->color.east[all->texX][texY];
		}
		else
		{
			if (all->stepX == -1)
				color = cub->win->color.north[all->texX][texY];
			else
				color = cub->win->color.south[all->texX][texY];
		}
		my_mlx_pixel_put(cub->big_win, x, i, color);
		i++;
	}
	return (i);
}

void	print_all(t_all *cub, int x, t_lodev *all)
{
	int	i;

	i = 0;
	while (i < all->drawStart)
	{
		my_mlx_pixel_put(cub->big_win, x, i, cub->map->ceiling);
		i++;
	}
	i = print_texture(cub, all, i, x);
	while (i < HEIGTH)
	{
		my_mlx_pixel_put(cub->big_win, x, i, cub->map->floor);
		i++;
	}
}

void	init_lodev(t_lodev *all)
{
	all->cameraX = 0;
	all->rayDirX = 0;
	all->rayDirY = 0;
	all->mapX = 0;
	all->mapY = 0;
	all->sideDistX = 0;
	all->sideDistY = 0;
	all->deltaDistX = 0;
	all->deltaDistY = 0;
	all->perpWallDist = 0;
	all->stepX = 0;
	all->stepY = 0;
	all->hit = 0;
	all->side = 0;
	all->lineHeight = 0;
	all->drawStart = 0;
	all->drawEnd = 0;
	all->wallX = 0;
	all->texX = 0;
	all->step = 0;
	all->texPos = 0;
}

void	*all_do(t_all *cub)
{
	int		x;
	t_lodev	all;

	x = 0;
	init_lodev(&all);
	while (x < WIDTH)
	{
		step1(&all, cub, x);
		step2(&all, cub);
		step3(&all, cub);
		step4(&all, cub);
		print_all(cub, x, &all);
		x++;
	}
	mlx_put_image_to_window(cub->big_win->mlx,
		cub->big_win->win, cub->big_win->img, 0, 0);
	print_mini_map(cub, -1, -1);
	return (NULL);
}
