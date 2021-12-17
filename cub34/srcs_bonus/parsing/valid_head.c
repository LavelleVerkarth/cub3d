/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:27:05 by lverkart          #+#    #+#             */
/*   Updated: 2021/09/10 16:27:07 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_no_map(char *str, t_all *cub)
{
	char	**buf;

	buf = ft_split(str, ' ');
	if (!buf || cub->map->no || ft_strcmp("NO", buf[0])
		|| buf[2] != NULL || ft_valid_name_image(buf[1]))
	{
		ft_free_t_map(cub);
		free_map(buf);
		return ;
	}
	cub->map->no = ft_strdup(buf[1]);
	free_map(buf);
}

void	ft_so_map(char *str, t_all *cub)
{
	char	**buf;

	buf = ft_split(str, ' ');
	if (!buf || cub->map->so || ft_strcmp("SO", buf[0])
		|| buf[2] != NULL || ft_valid_name_image(buf[1]))
	{
		ft_free_t_map(cub);
		free_map(buf);
		return ;
	}
	cub->map->so = ft_strdup(buf[1]);
	free_map(buf);
}

void	ft_we_map(char *str, t_all *cub)
{
	char	**buf;

	buf = ft_split(str, ' ');
	if (!buf || cub->map->we || ft_strcmp("WE", buf[0])
		|| buf[2] != NULL || ft_valid_name_image(buf[1]))
	{
		ft_free_t_map(cub);
		free_map(buf);
		return ;
	}
	cub->map->we = ft_strdup(buf[1]);
	free_map(buf);
}

void	ft_ea_map(char *str, t_all *cub)
{
	char	**buf;

	buf = ft_split(str, ' ');
	if (!buf || cub->map->ea || ft_strcmp("EA", buf[0])
		|| buf[2] != NULL || ft_valid_name_image(buf[1]))
	{
		ft_free_t_map(cub);
		free_map(buf);
		return ;
	}
	cub->map->ea = ft_strdup(buf[1]);
	free_map(buf);
}
