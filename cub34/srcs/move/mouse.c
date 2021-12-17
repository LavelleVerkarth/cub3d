/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladin <vpaladin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:12:21 by vpaladin          #+#    #+#             */
/*   Updated: 2021/09/10 16:12:22 by vpaladin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	turn_rigth(t_all **cub, double	oldDirX, double	oldPlaneX, int x)
{
	double	rotspeed;

	if (x > 0)
		rotspeed = TURN;
	else
		rotspeed = ROTSPEED;
	(*cub)->plr->Dir.x = (*cub)->plr->Dir.x * cos(-rotspeed)
		- (*cub)->plr->Dir.y * sin(-rotspeed);
	(*cub)->plr->Dir.y = oldDirX * sin(-rotspeed)
		+ (*cub)->plr->Dir.y * cos(-rotspeed);
	(*cub)->plr->planes.x = (*cub)->plr->planes.x
		* cos(-rotspeed) - (*cub)->plr->planes.y * sin(-rotspeed);
	(*cub)->plr->planes.y = oldPlaneX * sin(-rotspeed)
		+ (*cub)->plr->planes.y * cos(-rotspeed);
	return (1);
}

int	turn_left(t_all **cub, double oldDirX, double oldPlaneX, int x)
{
	double	rotspeed;

	if (x > 0)
		rotspeed = TURN;
	else
		rotspeed = ROTSPEED;
	(*cub)->plr->Dir.x = (*cub)->plr->Dir.x * cos(rotspeed)
		- (*cub)->plr->Dir.y * sin(rotspeed);
	(*cub)->plr->Dir.y = oldDirX * sin(rotspeed)
		+ (*cub)->plr->Dir.y * cos(rotspeed);
	(*cub)->plr->planes.x = (*cub)->plr->planes.x * cos(rotspeed)
		- (*cub)->plr->planes.y * sin(rotspeed);
	(*cub)->plr->planes.y = oldPlaneX * sin(rotspeed)
		+ (*cub)->plr->planes.y * cos(rotspeed);
	return (1);
}

int	mouse(int x, int y, t_all *cub)
{
	double	oldDirX;
	double	oldPlaneX;

	(void)y;
	oldDirX = cub->plr->Dir.x;
	oldPlaneX = cub->plr->planes.x;
	if (x > cub->x)
		turn_rigth(&cub, oldDirX, oldPlaneX, 1);
	else if (x < cub->x)
		turn_left(&cub, oldDirX, oldPlaneX, 1);
	cub->x = (long long)x;
	return (0);
}
