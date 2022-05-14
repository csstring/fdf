#include "fdf.h"
void	ft_rotate_x(double x, double y, double z, t_map *map, int i)
{
	double rad;

	rad = map -> deg_x;
	map -> rot.x[i] = x;
	map -> rot.y[i] = cos(rad) * y - sin(rad) * z;
	map -> rot.z[i] = sin(rad) * y + cos(rad) * z;
}

void	ft_rotate_y(double x, double y, double z, t_map *map, int i)
{
	double rad;

	rad = map -> deg_y;
	map -> rot.x[i] = cos(rad) * x + sin(rad) * z;
	map -> rot.y[i] = y;
	map -> rot.z[i] = -sin(rad) * x + cos(rad) * z;
}

void	ft_rotate_z(double x, double y, double z, t_map *map, int i)
{
	double rad;

	rad = map -> deg_z;
	map -> rot.x[i] = cos(rad) * x - sin(rad) * y;
	map -> rot.y[i] = sin(rad) * x + cos(rad) * y;
	map -> rot.z[i] = z;
}

void	ft_rotate(t_map *map)
{
	int	y;
	int	i;
	int	x;

	y = 0;
	i = 0;
	map -> rot.x = (double *)malloc(sizeof(double) * (map -> x * map -> y));
	map -> rot.y = (double *)malloc(sizeof(double) * (map -> x * map -> y));
	map -> rot.z = (double *)malloc(sizeof(double) * (map -> x * map -> y));
	while (y < map -> y)
	{
		x = 0;
		while (x < map -> x)
		{
			ft_rotate_x(x , y, map -> val[y][x], map, i);
			ft_rotate_y(map -> rot.x[i] ,map ->rot.y[i], map -> rot.z[i], map, i);
			ft_rotate_z(map -> rot.x[i] ,map ->rot.y[i], map -> rot.z[i], map, i);
			x++;
			i++;
			}
		y++;
	}
}
