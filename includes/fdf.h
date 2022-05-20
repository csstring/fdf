/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:33:43 by schoe             #+#    #+#             */
/*   Updated: 2022/05/20 16:49:18 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define PI			3.14159265
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define ESC		53
# define KEYPRESS	2
# define ZOOM_IN	69
# define ZOOM_OUT	78
# define Q			12
# define W			13
# define E			14
# define A			0
# define S			1
# define D			2
# define ONE		18
# define TWO		19
# define THREE		20
# define FOUR		21

typedef struct s_draw
{
	int	w;
	int	h;
	int	factor_x;
	int	factor_y;
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	color;
}	t_draw;

typedef struct s_rotate
{
	double	*x;
	double	*y;
	double	*z;
}	t_rotate;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}	t_data;

typedef struct s_map
{
	int			**val;
	int			x;
	int			y;
	double		distance;
	int			*color;
	double		deg_x;
	double		deg_y;
	double		deg_z;
	double		move_x;
	double		move_y;
	t_rotate	rot;
	t_data		win;
}	t_map;
//map
int		ft_map_len(char **str);
void	map_error(char *fdf, t_map *map);
void	make_mapval(int fd, t_map *map);
void	map_parsing(char *fdf, t_map *map);
void	get_color(t_map *map);
int		int_min(int *arr, t_map *map);
int		int_max(int *arr, t_map *map);
void	ft_clear_map(t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_init_win(t_map *map);
int		main_loop(t_map *map);
//deg, rotate
void	ft_rotate(t_map *map);
void	ft_rot_x(t_map *map, int i);
void	ft_rot_y(t_map *map, int i);
void	ft_rot_z(t_map *map, int i);
//draw
void	ft_draw_line(t_map *map);
void	ft_factor(t_map *map, int i, t_draw *val, int check);
void	ft_y_axis(t_draw *val, t_data *img);
void	ft_x_axis(t_draw *val, t_data *img);
void	ft_get_val(t_map *map, int i, t_draw *val, int check);
//distance
void	get_distance(t_map *map);
double	double_min(double *arr, t_map *map);
double	double_max(double *arr, t_map *map);
//color
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
//key
void	ft_key_parallel(int keycode, t_map *map);
void	ft_key_deg(int keycode, t_map *map);
int		ft_key_press(int keycode, t_map *map);
//error
void	ft_free_double(void **ptr, int i);
void	ft_error(char *str);
void	arg_error(int ac, char **av);
void	map_empty_check(char *fdf);

#endif
