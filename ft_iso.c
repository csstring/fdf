#include "fdf.h"

void	ft_rotate(t_map *map)
{
	int	y;
	int	i;
	int	x;
	double	psi;
	double	b;

	psi = PI / 5.104;
	b = PI / 4;
//	psi = PI / 6;
//	b = PI /6;
	y = 0;
	i = 0;
	map -> rot.x = (double *)malloc(sizeof(double) * (map -> x * map -> y));
	map -> rot.y = (double *)malloc(sizeof(double) * (map -> x * map -> y));
	while (y < map -> y)
	{
		x = 0;
		while (x < map -> x)
		{
		//	map -> rot.x[i] = (cos(b)*x - sin(b)*(map->val[y][x]));
		//	map -> rot.y[i] = (sin(psi)*sin(b)*x + cos(psi)*y + sin(psi) * cos(b) *(map->val[y][x]));
			map -> rot.x[i] = (x - y)*cos(0.523599);
			map -> rot.y[i] = -(map->val[y][x]) + (x + y)*sin(0.523599);
			x++;
			i++;
		}
		y++;
	}
}
double	ft_sort_max(double *arr, t_map *map)
{
	int		i;
	double	temp;
	double	max;

	i = 0;
	if (map -> x * map -> y == 1)
		return (arr[i]);
	max = arr[i];
	while (i < map -> x * map -> y)
	{
		temp = arr[i];
		if (temp > max)
			max = temp;
		i++;
	}
	return (max);
}

double	ft_sort_min(double *arr, t_map *map)
{
	int		i;
	double	temp;
	double	min;

	i = 0;
	if (map ->x * map -> y == 1)
		return (arr[i]);
	min = arr[i];
	while (i < map -> x * map -> y)
	{
		temp = arr[i];
		if (temp < min)
			min = temp;
		i++;
	}
	return (min);
}

void	get_distance(t_map *map)
{
	double	x_max;
	double	y_max;
	double	x_min;
	double	y_min;
	int		i;

	i = 0;
	x_max = ft_sort_max(map -> rot.x, map);
	y_max = ft_sort_max(map -> rot.y, map);
	x_min = ft_sort_min(map -> rot.x, map);
	y_min = ft_sort_min(map -> rot.y, map);
	if (1920 / map -> x < 1080 / map -> y)
		map -> distance = 1080 / map -> y / 5;
	else
		map -> distance = 1920 / map -> x / 5;
	map -> move_x = (2560 - map -> x * map ->distance) / 2;
	map -> move_y = (1440 - map -> x * map ->distance) / 2;
	while (i < map -> x * map -> y)
	{
		map -> rot.x[i] = map -> rot.x[i] * map -> distance + map -> move_x;
		map -> rot.y[i] = map -> rot.y[i] * map -> distance + map -> move_y;
		i++;
	}
}
