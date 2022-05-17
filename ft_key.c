/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:23:10 by schoe             #+#    #+#             */
/*   Updated: 2022/05/17 22:14:07 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:04:50 by schoe             #+#    #+#             */
/*   Updated: 2022/05/17 13:12:14 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 빨간버튼 구현:
#include "fdf.h"
#include <mlx.h>
void	ft_key_parallel(int keycode, t_map *map)
{
	if (keycode == one)
	{
		map -> deg_x = -PI / 2;
		map -> deg_y = 0;
		map -> deg_z = 0;
	}
	if (keycode == two)
	{
		map -> deg_x = 0;
		map -> deg_y = 0;
		map -> deg_z = 0;
	}
	if (keycode == three)
	{
		map -> deg_x = 0;
		map -> deg_y = -PI /2;
		map -> deg_z = 0;
	}
	if (keycode == four)
	{
		map -> deg_x = -0.615472907;
		map -> deg_y = PI / 4;
		map -> deg_z = 0;
	}
}
void	ft_key_deg(int keycode, t_map *map)
{
	if (keycode == W)
    	map -> deg_x += PI / 30;
    if (keycode == S)
    	map -> deg_x -= PI / 30;
    if (keycode == A)
    	map -> deg_z -= PI / 30;
    if (keycode == D)
    	map -> deg_z += PI / 30;
    if (keycode == Q)
    	map -> deg_y += PI / 30;
    if (keycode == E)
    	map -> deg_y -= PI / 30;
}

void	ft_key_move(int	keycode, t_map *map)
{	
	if (keycode == LEFT)
    	map -> move_x -= 15;
  	if (keycode == RIGHT)
    	map -> move_x += 15;
  	if (keycode == UP )//&& map -> move_y - 20/*- 150*/ > -600)
   		map -> move_y -= 15;
  	if (keycode == DOWN )//&& double_max(map -> rot.y, map) + + 150 < 1440)
    	map -> move_y += 10;
}
/*static int	diameter_check(t_map *map)
{
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
	double	rad;
	int		i;

	i = 0;
	x_max = double_max(map -> rot.x, map);
	while (i < map -> x * map -> y)
	{
		if (map -> rot.x[i] == x_max)
			y_max = map -> rot.y[i];
		i++;
	}
	x_min = double_min(map -> rot.x, map);
	y_min = double_min(map -> rot.y, map);
	rad = sqrt(pow((x_max - x_min) , 2) + pow((y_max - y_min) , 2) +\
			pow(double_max(map -> rot.z, map) - double_min(map-> rot.z, map) , 2));
	if (rad + y_min < 1250)
		return (1);
	return (0);
}
*/
int	ft_key_press(int keycode, t_map *map)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(map -> win.mlx, map -> win.img);
		mlx_destroy_window(map -> win.mlx, map -> win.mlx_win);
		exit(0);
	}
    if (keycode == zoom_in && (double_max(map -> rot.y, map) - double_min(map -> rot.y, map)) * 1.15 < 1440)
    	map -> distance += 0.15;
    if (keycode == zoom_out && map -> distance - 0.2 > 1)
    	map -> distance -= 0.2;
	ft_key_move(keycode, map);
//    if (!diameter_check(map))
//    	return (0);
    ft_key_deg(keycode, map);
    ft_key_parallel(keycode, map);
	return (0);
}
