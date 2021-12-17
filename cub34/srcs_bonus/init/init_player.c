/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladin <vpaladin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:11:56 by vpaladin          #+#    #+#             */
/*   Updated: 2021/09/10 16:11:57 by vpaladin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_data(t_all **cub, int dirx, int diry, double angle)
{
	(*cub)->plr->Dir.x = dirx;
	(*cub)->plr->Dir.y = diry;
	if ((*cub)->plr->Dir.x == 0)
		(*cub)->plr->planes.x = angle;
	else
		(*cub)->plr->planes.x = 0;
	if ((*cub)->plr->Dir.y == 0)
		(*cub)->plr->planes.y = angle;
	else
		(*cub)->plr->planes.y = 0;
}

static void	init_player_dir(t_all **cub, char o)
{
	if (o == 'N')
		player_data(cub, -1, 0, 0.66);
	else if (o == 'S')
		player_data(cub, 1, 0, -0.66);
	else if (o == 'E')
		player_data(cub, 0, 1, 0.66);
	else if (o == 'W')
		player_data(cub, 0, -1, -0.66);
}

static int	is_player(char c, t_all **cub, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		init_player_dir(cub, c);
		(*cub)->plr->pos.x = y + 0.5;
		(*cub)->plr->pos.y = x + 0.5;
		(*cub)->map->map[y][x] = '0';
		return (1);
	}
	return (0);
}

void	init_player(t_all *cub)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	cub->press = 0;
	map = cub->map->map;
	cub->plr = malloc(sizeof(t_plr));
	if (!cub->plr)
		error("Error malloc!\n");
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != 0)
		{
			if (is_player(map[y][x], &cub, x, y))
				break ;
			x++;
		}
		y++;
	}
}
