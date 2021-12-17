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

void	recording_map(t_all *cub, char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (!cub->map)
			return ;
		else if (!ft_strncmp("NO", map[i], 2))
			ft_no_map(map[i], cub);
		else if (!ft_strncmp("SO", map[i], 2))
			ft_so_map(map[i], cub);
		else if (!ft_strncmp("WE", map[i], 2))
			ft_we_map(map[i], cub);
		else if (!ft_strncmp("EA", map[i], 2))
			ft_ea_map(map[i], cub);
		else if (!ft_strncmp("F", map[i], 1))
			ft_f_map(map[i], cub);
		else if (!ft_strncmp("C", map[i], 1))
			ft_c_map(map[i], cub);
	}
}

void	ft_arrdup(char **arr, t_all *cub)
{
	int		i;
	int		j;

	cub->map->map = malloc(sizeof(char *) * (cub->map->max_x + 1));
	if (!cub->map->map)
		error("Error malloc!\n");
	i = -1;
	while (++i < cub->map->max_x)
	{
		cub->map->map[i] = malloc(sizeof(char) * cub->map->max_y + 10);
		cub->map->map[i][cub->map->max_y + 9] = 0;
		ft_memset(cub->map->map[i], ' ', cub->map->max_y + 9);
		j = -1;
		while (arr[i][++j])
			cub->map->map[i][j] = arr[i][j];
	}
	cub->map->map[i] = NULL;
}

int	valid_map(char **map, t_all *cub)
{
	int	m;

	cub->map->max_x = 0;
	cub->map->max_y = 0;
	m = valid_head(map);
	if (!m)
		error("Error malloc!\n");
	recording_map(cub, map);
	if (!cub->map)
		error("Error\nmap is not valid\n");
	if (valid_wall(&map[m], cub, -1, -1))
		error("Error\nmap is not valid\n");
	ft_arrdup(&map[m], cub);
	free_map(map);
	return (0);
}

void	in_map(t_all *cub)
{
	cub->map = malloc(sizeof(t_map));
	if (!cub->map)
		return ;
	cub->map->ea = NULL;
	cub->map->no = NULL;
	cub->map->so = NULL;
	cub->map->we = NULL;
	cub->map->map = NULL;
	cub->map->ceiling = -1;
	cub->map->floor = -1;
}

int	parse_map(char *file, t_all *cub)
{
	int		fd;
	char	*line;
	char	**map;

	if (ft_valid_name_file(file))
		return (1);
	in_map(cub);
	map = malloc(sizeof(char *));
	if (!map || !cub->map)
		error("Error malloc!\n");
	map[0] = NULL;
	fd = open(file, O_RDONLY, 0644);
	if (!fd)
		error2("Error\nconnot open file ", file);
	while (get_next_line(&line, fd))
	{
		map = add_map(map, &line);
		if (!map)
			error("Error malloc!\n");
	}
	close(fd);
	map = add_map(map, &line);
	if (!map)
		error("Error malloc!\n");
	return (valid_map(map, cub));
}
