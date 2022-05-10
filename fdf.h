#ifndef FDF_H
# define FDF_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265
typedef struct s_draw
{
	int	w;
	int	h;
	int	factor_x;
	int	factor_y;
}	t_draw;

typedef struct s_rotate
{
	double	*x;
	double	*y;
	double	*z;
} t_rotate;
typedef struct s_map
{
	int	**val;
	int	x;
	int	y;
	int	distance;
	int	move_x;
	int	move_y;
	t_rotate	rot;
}	t_map;
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	ft_free_double(char **str);
void	ft_error(const char *str);
int		ft_map_len(char **str);
void	map_error(char *fdf, t_map *map);
void	make_mapval(int	fd, t_map *map);
void	map_parsing(char *fdf, t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_rotate(t_map *map);
void	ft_draw_line(t_map *map, t_data *img);
void	ft_factor(int start_x, int start_y, int	end_x, int end_y, t_data *img);
void	ft_y_axis(int start_x, int start_y, int end_y, t_draw *val,t_data *img);
void	ft_x_axis(int start_x, int start_y, int end_x, t_draw *val, t_data *img);
void	get_distance(t_map *map);
double	ft_sort_min(double *arr, t_map *map);
double	ft_sort_max(double *arr, t_map *map);
void	ft_rotate(t_map *map);

#endif
