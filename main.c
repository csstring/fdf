#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"
void	ft_clear_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < 1440)
	{
		while (x < 2560)
		{
			my_mlx_pixel_put(&(map -> win), x, y , 0x00000000);
			x++;
		}
		x = 0;
		y++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data -> addr + (y * data -> line_length + x * (data -> bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main_loop(t_map *map)
{
	ft_clear_map(map);
	free(map -> rot.x);
	free(map -> rot.y);
	free(map -> rot.z);
	ft_rotate(map);
	get_distance(map);
	ft_draw_line(map);
	mlx_put_image_to_window(map -> win.mlx, map -> win.mlx_win, map -> win.img, 0 ,0);
	return (0);
}
void	put_pixel(t_map *map)
{
	int		y;
	int		i;

	y = 0;
	i = 0;
	map -> win.mlx = mlx_init();
	map -> win.mlx_win = mlx_new_window(map -> win.mlx, 2560, 1440, "schoe_test");
	map -> win.img = mlx_new_image(map -> win.mlx, 2560, 1440);
	map -> win.addr = mlx_get_data_addr(map -> win.img, &(map -> win.bits_per_pixel), &(map -> win.line_length), &(map -> win.endian));
}

int	main(int ac, char **av)
{
	t_map		map;

	ac = 0;
	map_parsing(av[1], &map);
	map.distance = 1;
	put_pixel(&map);
	ft_rotate(&map);
	get_distance(&map);
	ft_draw_line(&map);
	mlx_put_image_to_window(map.win.mlx, map.win.mlx_win, map.win.img, 0 ,0);
	mlx_hook(map.win.mlx_win, KeyPress, 0, ft_key_press, &map);
	mlx_loop_hook(map.win.mlx, main_loop, &map);
	mlx_loop(map.win.mlx);
	return (0);
}
