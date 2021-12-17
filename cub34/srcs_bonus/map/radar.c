/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:01 by lverkart          #+#    #+#             */
/*   Updated: 2021/09/10 16:14:02 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	scale_map(double x, double y, t_win *data, int color)
{
	t_point	end;

	(void)color;
	end.x = (x + 1.) * SCALE;
	end.y = (y + 1.) * SCALE;
	x *= SCALE;
	y *= SCALE;
	while ((int)y < (int)end.y)
	{
		while ((int)x < (int)end.x)
		{
			if (color == 1)
				my_mlx_pixel_put(data, x, y, 0xFFFFFF);
			else if (color == 0)
				my_mlx_pixel_put(data, x, y, 0x00FF00);
			else if (color == 2)
				my_mlx_pixel_put(data, x, y, 0x3F3F3F);
			else
				my_mlx_pixel_put(data, x, y, 0x000000);
			x += 1.0;
		}
		x -= SCALE;
		y++;
	}
}

int	in_circle_p(float x, float y, float rx, float ry)
{
	float	distance;
	float	rr;

	rr = 3.0;
	distance = sqrtf(powf(x - rx, 2) + powf(y - ry, 2)) - rr;
	if (distance > 0.)
		return (0);
	if (distance <= -3.)
		return (1);
	return (2);
}

int	in_circle_m(float x, float y, float rx, float ry)
{
	float	distance;
	float	rr;

	rr = 75.0;
	distance = sqrtf(powf(x - rx, 2) + powf(y - ry, 2)) - rr;
	if (distance > 0.)
		return (0);
	if (distance <= -3.)
		return (1);
	return (2);
}

void	print_radar(t_all *cub, int i, int j)
{
	int		drw;
	t_rad	rad;

	rad.w = 150;
	rad.h = 150;
	rad.x = rad.w / 2;
	rad.y = rad.h / 2;
	while (++i < rad.w + 20)
	{
		j = -1;
		while (++j < rad.h + 20)
		{
			drw = in_circle_m(i, j, rad.x, rad.y);
			if (drw == 0)
				my_mlx_pixel_put(cub->win, i, j, 0xFF000000);
			else if (drw == 2)
				my_mlx_pixel_put(cub->win, i, j, 0x00FF00);
			drw = in_circle_p(i, j, rad.x, rad.y);
			if (drw == 1 || drw == 2)
				my_mlx_pixel_put(cub->win, i, j, 0x00FF00);
		}
	}
	mlx_put_image_to_window(cub->win->mlx, cub->win->win,
		cub->win->img, 1120, 560);
}
