/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladin <vpaladin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:12:25 by vpaladin          #+#    #+#             */
/*   Updated: 2021/09/10 16:12:26 by vpaladin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forward_thrust(t_all **cub, char **map, double moveSpeed)
{
	if ((map[(int)((*cub)->plr->pos.x + (*cub)->plr->Dir.x
				* moveSpeed * 1.2)][(int)(*cub)->plr->pos.y]) == '0')
		(*cub)->plr->pos.x += (*cub)->plr->Dir.x * moveSpeed;
	if (map[(int)(*cub)->plr->pos.x][(int)((*cub)->plr->pos.y
				+ (*cub)->plr->Dir.y * moveSpeed * 1.2)] == '0')
		(*cub)->plr->pos.y += (*cub)->plr->Dir.y * moveSpeed;
}

void	backward(t_all **cub, char **map, double moveSpeed)
{
	if (map[(int)((*cub)->plr->pos.x - (*cub)->plr->Dir.x
			* moveSpeed * 1.2)][(int)(*cub)->plr->pos.y] == '0')
		(*cub)->plr->pos.x -= (*cub)->plr->Dir.x * moveSpeed;
	if (map[(int)((*cub)->plr->pos.x)][(int)((*cub)->plr->pos.y
			- (*cub)->plr->Dir.y * moveSpeed * 1.2)] == '0')
		(*cub)->plr->pos.y -= (*cub)->plr->Dir.y * moveSpeed;
}

void	sideways_movement(t_all **cub, char **map,
	double moveSpeed, int keycode)
{
	if (keycode == KEY_D)
	{
		if (map[(int)((*cub)->plr->pos.x + (*cub)->plr->Dir.y
				* moveSpeed * 1.2)][(int)((*cub)->plr->pos.y)] == '0')
			(*cub)->plr->pos.x += (*cub)->plr->Dir.y * moveSpeed;
		if (map[(int)((*cub)->plr->pos.x)][(int)((*cub)->plr->pos.y
				- (*cub)->plr->Dir.x * moveSpeed * 1.2)] == '0')
			(*cub)->plr->pos.y -= (*cub)->plr->Dir.x * moveSpeed;
	}
	if (keycode == KEY_A)
	{
		if ((map[(int)((*cub)->plr->pos.x - (*cub)->plr->Dir.y
					* moveSpeed * 1.2)][(int)(*cub)->plr->pos.y]) == '0')
			(*cub)->plr->pos.x -= (*cub)->plr->Dir.y * moveSpeed;
		if (map[(int)(*cub)->plr->pos.x][(int)((*cub)->plr->pos.y
				+ (*cub)->plr->Dir.x * moveSpeed * 1.2)] == '0')
			(*cub)->plr->pos.y += (*cub)->plr->Dir.x * moveSpeed;
	}
}

void	look(int keycode, t_all **cub, double oldDirX, double oldPlaneX)
{
	if (keycode == ARROW_RIGHT)
	{
		turn_rigth(cub, oldDirX, oldPlaneX, -1);
	}
	else if (keycode == ARROW_LEFT)
	{
		turn_left(cub, oldDirX, oldPlaneX, -1);
	}
}

int	keypress(int keycode, t_all *cub)
{
	char	**map;
	double	moveSpeed;
	double	oldDirX;
	double	oldPlaneX;

	map = cub->map->map;
	moveSpeed = 0.11;
	oldDirX = cub->plr->Dir.x;
	oldPlaneX = cub->plr->planes.x;
	if (keycode == KEY_W)
		forward_thrust(&cub, map, moveSpeed);
	else if (keycode == KEY_S)
		backward(&cub, map, moveSpeed);
	else if (keycode == KEY_D || keycode == KEY_A)
		sideways_movement(&cub, map, moveSpeed, keycode);
	else if (keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		look(keycode, &cub, oldDirX, oldPlaneX);
	else if (keycode == ESC)
		exit(0);
	return (0);
}
