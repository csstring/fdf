#include "fdf.h"
#include <unistd.h>
void	ft_x_axis(t_draw *val, t_data *img)
{
	int	det;

	det = 2 * val -> h - val -> w;
	while (val->start_x != val -> end_x)
	{
		if (det < 0)
			det += 2 *val -> h;
		else
		{
			val -> start_y += val -> factor_y;
			det += 2 * val->h - 2 * val->w;
		}
		my_mlx_pixel_put(img, val -> start_x, val -> start_y, val -> color);
		val -> start_x += val -> factor_x;
	}
}

void	ft_y_axis(t_draw *val, t_data *img)
{

	int	det;

	det = 2 * val->w - val->h;
	while (val->start_y != val->end_y)
	{
		if (det < 0)
			det += 2 * val->w;
		else
		{
			val->start_x += val -> factor_x;
			det += 2 *val->w - 2 * val -> h;
		}
		my_mlx_pixel_put(img, val->start_x, val->start_y, val -> color);
		val -> start_y += val -> factor_y;
	}
}

void	ft_get_val(t_map *map, int i, t_draw *val, int check)
{	
	val -> start_x = map -> rot.x[i];
	val -> start_y = map -> rot.y[i];
	if (check == 1)
	{
		val->end_x = map -> rot.x[i + 1];
		val->end_y = map -> rot.y[i + 1];
		if (map -> color[i] > map -> color[i + 1])
				val -> color = map -> color[i];
		else
			val -> color = map -> color[i + 1];
	}
	else
	{
		val->end_x = map -> rot.x[i + map -> x];
		val->end_y = map -> rot.y[i + map -> x];
		if (map -> color[i] > map -> color[i + map -> x])
			val -> color = map -> color[i];
		else
			val -> color = map -> color[i + map -> x];
	}
}

void	ft_factor(t_map *map, int i,t_draw *val, t_data *img, int check)
{
	ft_get_val(map, i, val, check);
	val->w = abs(val -> start_x - val -> end_x);
	val->h = abs(val -> start_y - val -> end_y);
	if (val -> start_x > val -> end_x)
		val->factor_x = -1;
	else
		val->factor_x = 1;
	if (val -> start_y > val -> end_y)
		val->factor_y = -1;
	else
		val->factor_y = 1;
	if (val->w > val->h)
		ft_x_axis(val, img);
	else
		ft_y_axis(val, img);
}

void	ft_draw_line(t_map *map)
{
	int	x;
	int	y;
	int	i;
	t_draw	val;

	i = 0;
	y = 0;
	while (y < map -> y)
	{
		x = 0;
		while (x < map -> x)
		{
			if (x != map -> x - 1)
				ft_factor(map, i, &val, map -> win, 1);
			if (y != map -> y - 1)
				ft_factor(map, i, &val, map -> win, 2);
			x++;
			i++;
		}
		y++;
	}
}
