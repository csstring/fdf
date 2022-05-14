#include "fdf.h"
void	ft_rotate_x(double x, double y, double z, t_map *map, int i)
{
	double rad;

	rad = 0;
	rad = 0.955323419;
	rad = PI/2 ;
	map -> rot.x[i] = x;
	map -> rot.y[i] = cos(rad) * y - sin(rad) * z;
	map -> rot.z[i] = sin(rad) * y + cos(rad) * z;
}
void	ft_rotate_x2(double x, double y, double z, t_map *map, int i)
{
	double rad;

	rad = 0;
//	printf("y:%f\nz:%f",y,z);
//	rad = -atan((double)10 / (double)map -> y);
	rad = -0.615472907; 
	map -> rot.x[i] = x;
	map -> rot.y[i] = cos(rad) * y - sin(rad) * z;
	map -> rot.z[i] = sin(rad) * y + cos(rad) * z;
}
void	ft_rotate_y(double x, double y, double z, t_map *map, int i)
{
	double rad;

//	rad = 0;
	rad = PI/4;
//	rad = atan((double)map -> x / (double)map -> y);
	map -> rot.x[i] = cos(rad) * x + sin(rad) * z;
	map -> rot.y[i] = y;
	map -> rot.z[i] = -sin(rad) * x + cos(rad) * z;
}

void	ft_rotate_z(double x, double y, double z, t_map *map, int i)
{
	double rad;

	rad = 0;
	rad = -PI / 8;
	rad = atan(map -> rot.y[i] / map -> rot.z[i]);
	map -> rot.x[i] = cos(rad) * x - sin(rad) * y;
	map -> rot.y[i] = sin(rad) * x + cos(rad) * y;
	map -> rot.z[i] = z;
}

void	ft_rotate(t_map *map)
{
	int	y;
	int	i;
	int	x;
//	double	psi;
//	double	b;
	double	rad;

//	psi = PI / 5.104;
//	b = PI / 4;
	rad = PI / 6;
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
			ft_rotate_y(map -> rot.x[i] ,map ->rot.y[i], map ->rot.z[i], map, i);
			ft_rotate_x2(map -> rot.x[i] ,map ->rot.y[i], map -> rot.z[i], map, i);
		//	map -> rot.x[i] = (cos(b)*x - sin(b)*(map->val[y][x]));
		//	map -> rot.y[i] = (sin(psi)*sin(b)*x + cos(psi)*y + sin(psi) * cos(b) *(map->val[y][x]));
	//		map -> rot.x[i] = (map -> rot.x[i] - map -> rot.y[i]) * cos(rad);
	//		map -> rot.y[i] = -(map -> rot.z[i]) + (map -> rot.x[i] + map -> rot.y[i]) * sin(rad);
//			map -> rot.x[i] = (x - y)*cos(0.523599);
//			map -> rot.y[i] = -(map->val[y][x]) + (x + y)*sin(0.523599);
//			map -> rot.x[i] = cos(rad)*map->rot.x[i] - sin(rad) * map -> rot.y[i];
//			map -> rot.y[i] = sin(rad) * y - sin(rad) * map -> val[y][x];
			x++;
			i++;
			}
		y++;
	}
}
