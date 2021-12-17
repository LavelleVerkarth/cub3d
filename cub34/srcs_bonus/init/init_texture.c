/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladin <vpaladin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:12:01 by vpaladin          #+#    #+#             */
/*   Updated: 2021/09/10 16:12:02 by vpaladin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	color_pixel_texture(t_img *img, int i, int j)
{
	char			*addr;
	unsigned int	color;

	addr = img->addr + (j * img->line_l + i * (img->bpp / 8));
	color = *(unsigned int *)addr;
	return (color);
}

void static	get_color_texure(t_all *cub, int ***color, char *way)
{
	int		w;
	int		h;
	int		i;
	int		j;
	t_img	img;

	i = -1;
	img.img = mlx_xpm_file_to_image(cub->win->mlx, way, &w, &h);
	if (!img.img)
		error("Error xpm!\n");
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.en);
	(*color) = malloc(sizeof(int *) * w);
	if (!(*color))
		error("Error malloc!\n");
	while (++i < TEX_WIDTH)
	{
		j = -1;
		(*color)[i] = malloc(sizeof(int) * h);
		while (++j < TEX_HEIGHT)
			(*color)[i][j] = color_pixel_texture(&img, i, j);
	}
}

void	init_texture(t_all *cub)
{
	get_color_texure(cub, &cub->win->color.north, cub->map->no);
	get_color_texure(cub, &cub->win->color.south, cub->map->so);
	get_color_texure(cub, &cub->win->color.west, cub->map->we);
	get_color_texure(cub, &cub->win->color.east, cub->map->ea);
}
