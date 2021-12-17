/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaladin <vpaladin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:49:54 by lverkart          #+#    #+#             */
/*   Updated: 2021/09/06 13:30:14 by vpaladin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define SCALE 		9
# define MID		8.4
# define TURN 		0.05
# define ROTSPEED	0.055
# define WIDTH		1280
# define HEIGTH		720
# define TEX_WIDTH	64
# define TEX_HEIGHT	64
# define SPACE 		49

# define ARROW_UP		126
# define ARROW_DOWN		125
# define ARROW_LEFT		123
# define ARROW_RIGHT	124

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define ESC			53

typedef struct s_rad
{
	float	w;
	float	x;
	float	y;
	float	h;

}t_rad;

typedef struct s_img
{
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
}t_img;

typedef struct s_color
{
	int			**north;
	char		*patn_n;
	int			**south;
	char		*patn_s;
	int			**west;
	char		*patn_w;
	int			**east;
	char		*patn_e;
}t_color;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
	t_color		color;
}t_win;

typedef struct s_point
{
	double			x;
	double			y;
}t_point;

typedef struct s_map
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		**map;
	char		**free_map;
	int			floor;
	int			ceiling;
	int			max_x;
	int			max_y;

}t_map;

typedef struct s_lodev
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;	
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	double	wallX;
	int		texX;
	double	step;
	double	texPos;
}				t_lodev;

typedef struct s_player
{
	t_point		old_loc;
	float		start;
	float		end;
	t_point		Dir;
	t_point		pos;
	t_point		planes;
}t_plr;

typedef struct s_all
{
	t_win		*win;
	t_win		*big_win;
	t_plr		*plr;
	t_map		*map;
	long long	x;
	int			press;
}t_all;

int		parse_map(char *file, t_all *cub);
void	init_player(t_all *cub);
void	init_mlx_big_map(t_all *cub);
void	init_mlx_minimap(t_all *cub);
void	init_texture(t_all *cub);

void	print_mini_map(t_all *cub, int i, int j);
void	do_it(t_all **cub);
void	*all_do(t_all *cub);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);

void	step1(t_lodev *all, t_all *cub, int x);
void	step2(t_lodev *all, t_all *cub);
void	step3(t_lodev *all, t_all *cub);
void	step4(t_lodev *all, t_all *cub);

int		keypress(int keycode, t_all *cub);
int		close_all(int keycode, t_all *cub);
int		mouse(int x, int y, t_all *cub);
int		turn_left(t_all **cub, double oldDirX, double oldPlaneX, int x);
int		turn_rigth(t_all **cub, double	oldDirX, double	oldPlaneX, int x);
void	forward_thrust(t_all **cub, char **map, double moveSpeed);
void	backward(t_all **cub, char **map, double moveSpeed);
void	sideways_movement(t_all **cub, char **map,
			double moveSpeed, int keycode);

void	error(char *s);
void	error2(char *s1, char *s2);

void	scale_map(double x, double y, t_win *data, int color);
void	print_radar(t_all *cub, int i, int j);

int		valid_wall(char **map, t_all *cub, int i, int j);
int		get_next_line(char **line, int fd);
void	free_map(char **map);
char	**add_map(char **map, char **new);
void	ft_free_t_map(t_all *cub);
int		ft_valid_name_image(char *file);
int		valid_head(char **map);
int		ft_valid_name_file(char *file);
int		create_trgb(int t, int r, int g, int b);
void	ft_no_map(char *str, t_all *cub);
void	ft_so_map(char *str, t_all *cub);
void	ft_we_map(char *str, t_all *cub);
void	ft_ea_map(char *str, t_all *cub);
void	ft_f_map(char *str, t_all *cub);
void	ft_c_map(char *str, t_all *cub);

#endif
