#ifndef FDF_H
# define FDF_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265
#define	UP          126
#define	DOWN        125
#define	LEFT        123
#define	RIGHT       124
#define ESC         53
#define KeyPress    2
#define KeyRelease  3

//color main지우기:
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
} t_rotate;
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
	int	**val;
	int	x;
	int	y;
	int	distance;
	int	*color;
	double	deg_x;
	double	deg_y;
	double	deg_z;
	double	move_x;
	double	move_y;
	t_rotate	rot;
	t_data	*win;
}	t_map;
void	ft_free_double(char **str);
void	ft_error(const char *str);
int		ft_map_len(char **str);
void	map_error(char *fdf, t_map *map);
void	make_mapval(int	fd, t_map *map);
void	map_parsing(char *fdf, t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_rotate(t_map *map);
void	ft_draw_line(t_map *map);
void	ft_factor(t_map *map, int i,t_draw *val, t_data *img, int check);
void	ft_y_axis(t_draw *val, t_data *img);
void	ft_x_axis(t_draw *val, t_data *img);
void	ft_get_val(t_map *map, int i, t_draw *val, int check);
void	get_distance(t_map *map);
double	ft_sort_min(double *arr, t_map *map);
double	ft_sort_max(double *arr, t_map *map);
void	ft_rotate(t_map *map);
char	*get_next_line(int fd);
void	ft_free_double(char **);
void	ft_error(const char *str);//ft_printf_로 수정
int		create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);
#endif
