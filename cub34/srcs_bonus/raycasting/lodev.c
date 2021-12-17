/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lodev.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladin <vpaladin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:12:32 by vpaladin          #+#    #+#             */
/*   Updated: 2021/09/10 16:12:33 by vpaladin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	step1(t_lodev *all, t_all *cub, int x)
{
	all->cameraX = 2 * x / (double)WIDTH - 1;
	all->rayDirX = cub->plr->Dir.x + cub->plr->planes.x * all->cameraX;
	all->rayDirY = cub->plr->Dir.y + cub->plr->planes.y * all->cameraX;
	all->mapX = (int)cub->plr->pos.x;
	all->mapY = (int)cub->plr->pos.y;
	all->deltaDistX = sqrt(1 + (all->rayDirY * all->rayDirY)
			/ (all->rayDirX * all->rayDirX));
	all->deltaDistY = sqrt(1 + (all->rayDirX * all->rayDirX)
			/ (all->rayDirY * all->rayDirY));
	all->hit = 0;
}

void	step2(t_lodev *all, t_all *cub)
{
	if (all->rayDirX < 0)
	{
		all->stepX = -1;
		all->sideDistX = (cub->plr->pos.x - all->mapX) * all->deltaDistX;
	}
	else
	{
		all->stepX = 1;
		all->sideDistX = (all->mapX + 1.0 - cub->plr->pos.x) * all->deltaDistX;
	}
	if (all->rayDirY < 0)
	{
		all->stepY = -1;
		all->sideDistY = (cub->plr->pos.y - all->mapY) * all->deltaDistY;
	}
	else
	{
		all->stepY = 1;
		all->sideDistY = (all->mapY + 1.0 - cub->plr->pos.y) * all->deltaDistY;
	}
}

void	step3(t_lodev *all, t_all *cub)
{
	while (all->hit == 0)
	{
		if (all->sideDistX < all->sideDistY)
		{
			all->sideDistX += all->deltaDistX;
			all->mapX += all->stepX;
			all->side = 0;
		}
		else
		{
			all->sideDistY += all->deltaDistY;
			all->mapY += all->stepY;
			all->side = 1;
		}
		if (cub->map->map[all->mapX][all->mapY] == '1')
			all->hit = 1;
	}
	if (all->side == 0)
		all->perpWallDist = (all->mapX - cub->plr->pos.x
				+ (1 - all->stepX) / 2) / all->rayDirX;
	else
		all->perpWallDist = (all->mapY - cub->plr->pos.y
				+ (1 - all->stepY) / 2) / all->rayDirY;
}

void	step4(t_lodev *all, t_all *cub)
{
	all->lineHeight = (int)(HEIGTH / all->perpWallDist);
	all->drawStart = -all->lineHeight / 2 + HEIGTH / 2;
	if (all->drawStart < 0)
		all->drawStart = 0;
	all->drawEnd = all->lineHeight / 2 + HEIGTH / 2;
	if (all->drawEnd >= HEIGTH)
		all->drawEnd = HEIGTH - 1;
	if (all->side == 0)
		all->wallX = cub->plr->pos.y + all->perpWallDist * all->rayDirY;
	else
		all->wallX = cub->plr->pos.x + all->perpWallDist * all->rayDirX;
	all->wallX -= floor ((all->wallX));
	all->texX = (int)(all->wallX * (double)TEX_WIDTH);
	if (all->side == 0 && all->rayDirX > 0)
		all->texX = TEX_WIDTH - all->texX - 1;
	if (all->side == 1 && all->rayDirY < 0)
		all->texX = TEX_WIDTH - all->texX - 1;
	all->step = 1.0 * TEX_HEIGHT / all->lineHeight;
	all->texPos = (all->drawStart - HEIGTH
			/ 2 + all->lineHeight / 2) * all->step;
}
