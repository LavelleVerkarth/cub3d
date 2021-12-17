/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:14:09 by lverkart          #+#    #+#             */
/*   Updated: 2021/09/10 16:14:11 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_up_left(t_all *cub, int i, double dx, double dy)
{
	int	j;

	j = -1;
	while (++j < SCALE)
	{
		if ((int)cub->plr->pos.x - i >= 0)
		{
			if ((int)cub->plr->pos.y - j >= 0)
			{
				if (cub->map->map[(int)cub->plr->pos.x
						- i][(int)cub->plr->pos.y - j] == '1')
					scale_map(MID - j - dx, MID - i - dy, cub->win, 1);
				else
					scale_map(MID - j - dx, MID - i - dy, cub->win, 3);
			}
			else
				scale_map(MID - j - dx, MID - i - dy, cub->win, 3);
		}
		else
			scale_map(MID - j - dx, MID - i - dy, cub->win, 3);
	}
}

void	print_up_right(t_all *cub, int i, double dx, double dy)
{
	int	j;

	j = -1;
	while (++j < SCALE)
	{
		if ((int)cub->plr->pos.x - i >= 0)
		{
			if (cub->map->map[(int)cub->plr->pos.x
					- i][(int)cub->plr->pos.y + j] == '1')
				scale_map(MID + j - dx, MID - i - dy, cub->win, 1);
			else
				scale_map(MID + j - dx, MID - i - dy, cub->win, 3);
		}
		else
			scale_map(MID + j - dx, MID - i - dy, cub->win, 3);
	}
	if ((int)cub->plr->pos.y - j < 0)
		while (++j < SCALE)
			scale_map(MID + j - 1 - dx, MID - i - dy, cub->win, 3);
}

void	print_down_left(t_all *cub, int i, double dx, double dy)
{
	int	j;

	j = -1;
	while (++j < SCALE)
	{
		if ((int)cub->plr->pos.x + i >= 0)
		{
			if ((int)cub->plr->pos.y - j >= 0)
			{
				if (cub->map->map[(int)cub->plr->pos.x
						+ i][(int)cub->plr->pos.y - j] == '1')
					scale_map(MID - j - dx, MID + i - dy, cub->win, 1);
				else
					scale_map(MID - j - dx, MID + i - dy, cub->win, 3);
			}
			else
				scale_map(MID - j - dx, MID + i - dy, cub->win, 3);
		}
		else
			scale_map(MID - j - dx, MID + i - dy, cub->win, 3);
	}
}

void	print_down_right(t_all *cub, int i, double dx, double dy)
{
	int	j;

	j = -1;
	while (++j < SCALE && cub->map->map[(int)cub->plr->pos.x
			+ i][(int)cub->plr->pos.y + j])
	{
		if ((int)cub->plr->pos.x + i >= 0)
		{
			if (cub->map->map[(int)cub->plr->pos.x
					+i][(int)cub->plr->pos.y + j] == '1')
				scale_map(MID + j - dx, MID + i - dy, cub->win, 1);
			else
				scale_map(MID + j - dx, MID + i - dy, cub->win, 3);
		}
		else
			scale_map(MID + j - dx, MID + i - dy, cub->win, 3);
	}
	if (!cub->map->map[(int)cub->plr->pos.x + i][(int)cub->plr->pos.y + j])
		while (++j < SCALE)
			scale_map(MID + j - 1 - dx, MID + i - dy, cub->win, 3);
}

void	print_mini_map(t_all *cub, int i, int j)
{
	double	dx;
	double	dy;

	dy = cub->plr->pos.x - (int)cub->plr->pos.x;
	dx = cub->plr->pos.y - (int)cub->plr->pos.y;
	while (++i < SCALE)
	{
		print_up_left(cub, i, dx, dy);
		print_up_right(cub, i, dx, dy);
	}
	i = -1;
	while (++i < SCALE && cub->map->map[(int)cub->plr->pos.x + i])
	{
		print_down_left(cub, i, dx, dy);
		print_down_right(cub, i, dx, dy);
	}
	if (!cub->map->map[(int)cub->plr->pos.x + i])
	{
		while (++j < SCALE)
		{
			scale_map(MID + j - 1 - dx, MID + i - 1 - dy, cub->win, 3);
			scale_map(MID - j - 1 - dx, MID + i - dy, cub->win, 3);
		}
	}
	print_radar(cub, -1, -1);
}
