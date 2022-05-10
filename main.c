#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data -> addr + (y * data -> line_length + x * (data -> bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_pixel(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
//	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	img = (t_data *)malloc(sizeof(t_data));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2560, 1440, "schoe_test");
	img -> img = mlx_new_image(mlx, 2560, 1440);
	img -> addr = mlx_get_data_addr(img -> img, &(img -> bits_per_pixel), &(img -> line_length), &(img -> endian));
	//함수로 뜯어낼곳
	ft_rotate(map);
	get_distance(map);
/*	while (y < map -> y)
	{
		x = 0;
		while (x < map -> x)
		{
			my_mlx_pixel_put(img, map -> rot.x[i], map -> rot.y[i], 0x00FF0000);
			//printf("x :%d y: %d\n",(int)(map -> rot.x[i]+600), (int)(map->rot.y[i]+600));
			x++;
			i++;
		}
		y++;
	}
	// 여기까지*/
	ft_draw_line(map, img);
	mlx_put_image_to_window(mlx, mlx_win, img -> img, 0 ,0);
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	t_map	map;

	ac = 0;
	map_parsing(av[1], &map);
	put_pixel(&map);
	return (0);
}
