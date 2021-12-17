/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverkart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:19:08 by lverkart          #+#    #+#             */
/*   Updated: 2021/09/10 16:19:10 by lverkart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_next_line(char **line, int fd)
{
	char	buff;
	int		i;
	char	*tmp;

	i = 0;
	if (!line)
		return (-1);
	tmp = ft_strdup("");
	while (read(fd, &buff, 1) > 0)
	{
		if (buff == '\n')
		{
			*line = tmp;
			return (1);
		}
		tmp = ft_str_addchar(tmp, buff);
	}
	*line = tmp;
	return (0);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (map[++i])
	{
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
	map = NULL;
}

char	**add_map(char **map, char **new)
{
	int		i;
	char	**ret;

	i = 0;
	while (map[i])
		i++;
	ret = malloc(sizeof(char *) * (i + 2));
	if (!ret)
		error("Error malloc!\n");
	i = -1;
	while (map[++i])
	{
		ret[i] = ft_strdup(map[i]);
		if (!ret[i])
			error("Error malloc!\n");
	}
	free_map(map);
	ret[i] = ft_strdup(*new);
	if (!ret[i])
		error("Error malloc!\n");
	ret[++i] = NULL;
	free(*new);
	return (ret);
}

int	valid_wall_space_name(int i, int j, char **map)
{
	int	n;

	if (i != 0 && j != 0 && map[i][j + 1] && map[i + 1])
	{
		n = 0;
		while (map[i + 1][n] && map[i - 1][n] && n != j)
			n++;
		if (n != j || map[i][j + 1] == ' ' || map[i][j - 1] == ' '
			|| map[i - 1][n] == ' ' || map[i + 1][n] == ' '
			|| !map[i + 1][n + 1] || !map[i - 1][n + 1]
			|| map[i + 1][n - 1] == ' '
			|| map[i - 1][n - 1] == ' '
			|| map[i - 1][n + 1] == ' ' || map[i + 1][n + 1] == ' ')
			return (1);
	}
	else
		return (1);
	return (0);
}

int	valid_wall(char **map, t_all *cub, int i, int j)
{
	int	pers;

	pers = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'W'
				&& map[i][j] != 'E' && map[i][j] != ' ')
				return (1);
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				if (pers++)
					return (1);
			if (map[i][j] != '1' && map[i][j] != ' ')
				if (valid_wall_space_name(i, j, map))
					return (1);
		}
		if (cub->map->max_y < j)
			cub->map->max_y = j;
	}
	cub->map->max_x = i;
	return (0);
}
