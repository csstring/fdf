/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:51:08 by schoe             #+#    #+#             */
/*   Updated: 2022/05/20 17:00:21 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "./minilibx/mlx.h"

int	main_loop(t_map *map)
{
	ft_clear_map(map);
	if (map -> rot.x != 0)
	{
		free(map -> rot.x);
		free(map -> rot.y);
		free(map -> rot.z);
	}
	ft_rotate(map);
	get_distance(map);
	ft_draw_line(map);
	mlx_put_image_to_window(map -> win.mlx, map -> win.mlx_win, \
			map -> win.img, 0, 0);
	return (0);
}

void	ft_init_win(t_map *map)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	map -> win.mlx = mlx_init();
	map -> win.mlx_win = mlx_new_window(map -> win.mlx, 2560, 1440, "fdf");
	map -> win.img = mlx_new_image(map -> win.mlx, 2560, 1440);
	map -> win.addr = mlx_get_data_addr(map -> win.img, \
			&(map -> win.bits_per_pixel), &(map -> win.line_length), \
			&(map -> win.endian));
}

int	main(int ac, char **av)
{
	t_map	map;

	arg_error(ac, av);
	ft_memset(&map, 0, sizeof(map));
	map_parsing(av[1], &map);
	map.distance = 1;
	ft_init_win(&map);
	ft_rotate(&map);
	get_distance(&map);
	ft_draw_line(&map);
	mlx_put_image_to_window(map.win.mlx, map.win.mlx_win, map.win.img, 0, 0);
	mlx_hook(map.win.mlx_win, KEYPRESS, 0, ft_key_press, &map);
	mlx_loop(map.win.mlx);
	return (0);
}
