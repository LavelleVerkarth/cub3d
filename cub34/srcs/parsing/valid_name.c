/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:23:37 by lverkart          #+#    #+#             */
/*   Updated: 2021/09/10 16:23:39 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_valid_name_file(char *file)
{
	char	*n;

	n = ft_strrchr(file, '.');
	if (n)
		if (!ft_strcmp("cub", &n[1]))
			return (0);
	error2("Error\nnot correct format ", file);
	return (1);
}

int	valid_head(char **map)
{
	int		i;
	char	*n;
	int		j;

	i = -1;
	while (map[++i])
	{
		if (ft_strncmp("NO", map[i], 2) && ft_strncmp("SO", map[i], 2)
			&& ft_strncmp("WE", map[i], 2) && ft_strncmp("EA", map[i], 2)
			&& ft_strncmp("F", map[i], 1) && ft_strncmp("C", map[i], 1)
			&& map[i][0] != 0)
		{
			n = ft_strchr(map[i], '1');
			if (!n)
				error("Error\nmap is not valid\n");
			j = -1;
			while (&map[i][++j] != n)
				if (map[i][j] != ' ')
					error("Error\nmap is not valid\n");
			break ;
		}
	}
	if (!map[i])
		error("Error\nmap is not valid\n");
	return (i);
}

int	ft_valid_name_image(char *file)
{
	char	*n;

	n = ft_strrchr(file, '.');
	if (n)
		if (!ft_strcmp("xpm", &n[1]))
			return (0);
	return (1);
}

void	ft_free_t_map(t_all *cub)
{
	free(cub->map->no);
	cub->map->no = NULL;
	free(cub->map->so);
	cub->map->so = NULL;
	free(cub->map->ea);
	cub->map->ea = NULL;
	free(cub->map->we);
	cub->map->we = NULL;
	free(cub->map->map);
	cub->map->map = NULL;
	free(cub->map);
	cub->map = NULL;
}
