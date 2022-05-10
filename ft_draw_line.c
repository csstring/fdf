#include "fdf.h"
#include <unistd.h>
void	ft_x_axis(int start_x, int start_y, int end_x, t_draw *val, t_data *img)
{
	int	det;

	det = 2 * val -> h - val -> w;
	while (start_x != end_x)
	{
		if (det < 0)
			det += 2 *val -> h;
		else
		{
			start_y += val -> factor_y;
			det += 2 * val->h - 2 * val->w;
		}
		my_mlx_pixel_put(img, start_x, start_y, 0x00FF0000);
		start_x += val -> factor_x;
	}
}

void	ft_y_axis(int start_x, int start_y, int end_y, t_draw *val,t_data *img)
{

	int	det;

	det = 2 * val->w - val->h;
	while (start_y != end_y)
	{
		if (det < 0)
			det += 2 * val->w;
		else
		{
			start_x += val -> factor_x;
			det += 2 *val->w - 2 * val -> h;
		}
		my_mlx_pixel_put(img, start_x, start_y, 0x000000FF);
		start_y += val -> factor_y;
	}
}
void	ft_factor(int start_x, int start_y, int	end_x, int end_y, t_data *img)
{
	t_draw	val;

	val.w = abs(start_x - end_x);
	val.h = abs(start_y - end_y);
	if (start_x > end_x)
		val.factor_x = -1;
	else
		val.factor_x = 1;
	if (start_y > end_y)
		val.factor_y = -1;
	else
		val.factor_y = 1;
	if (val.w > val.h)
		ft_x_axis(start_x, start_y, end_x, &val, img);
	else
		ft_y_axis(start_x, start_y, end_y, &val, img);
}

void	ft_draw_line(t_map *map, t_data *img)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < map -> y)
	{
		x = 0;
		while (x < map -> x)
		{
			if (x != map -> x - 1)
				ft_factor(map->rot.x[i], map->rot.y[i], map->rot.x[i + 1], map->rot.y[i + 1], img);
			if (y != map -> y - 1)
				ft_factor(map->rot.x[i], map->rot.y[i], map->rot.x[i + map -> x], map -> rot.y[i + map -> x], img);
			x++;
			i++;
		}
		y++;
	}
}
