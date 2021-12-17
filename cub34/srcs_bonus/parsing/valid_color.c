/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:29:39 by lverkart          #+#    #+#             */
/*   Updated: 2021/09/10 16:29:42 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_f_map(char *str, t_all *cub)
{
	char	**buf;
	char	**tmp;
	int		col[3];

	if (cub->map->floor != -1)
		return (ft_free_t_map(cub));
	buf = ft_split(str, ' ');
	if (!buf || ft_strcmp("F", buf[0]) || buf[2] != NULL)
		error("Error\nmap is not valid\n");
	tmp = ft_split(buf[1], ',');
	free_map(buf);
	if (!tmp || !ft_is_digits(tmp[0])
		|| !ft_is_digits(tmp[1]) || !ft_is_digits(tmp[2]))
		error("Error\nmap is not valid\n");
	col[0] = ft_atoi(tmp[0]);
	col[1] = ft_atoi(tmp[1]);
	col[2] = ft_atoi(tmp[2]);
	free_map(tmp);
	if (col[0] < 0 || col[0] > 255 || col[1] < 0
		|| col[1] > 255 || col[2] < 0 || col[2] > 255)
		ft_free_t_map(cub);
	else
		cub->map->floor = create_trgb(0, col[0], col[1], col[2]);
}

void	ft_c_map(char *str, t_all *cub)
{
	char	**buf;
	char	**tmp;
	int		col[3];

	if (cub->map->ceiling != -1)
		return (ft_free_t_map(cub));
	buf = ft_split(str, ' ');
	if (!buf || ft_strcmp("C", buf[0]) || buf[2] != NULL)
		error("Error\nmap is not valid\n");
	tmp = ft_split(buf[1], ',');
	free_map(buf);
	if (!tmp || !ft_is_digits(tmp[0])
		|| !ft_is_digits(tmp[1]) || !ft_is_digits(tmp[2]))
		error("Error\nmap is not valid\n");
	col[0] = ft_atoi(tmp[0]);
	col[1] = ft_atoi(tmp[1]);
	col[2] = ft_atoi(tmp[2]);
	free_map(tmp);
	if (col[0] < 0 || col[0] > 255 || col[1] < 0
		|| col[1] > 255 || col[2] < 0 || col[2] > 255)
		ft_free_t_map(cub);
	else
		cub->map->ceiling = create_trgb(0, col[0], col[1], col[2]);
}
