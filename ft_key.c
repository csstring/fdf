/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:04:50 by schoe             #+#    #+#             */
/*   Updated: 2022/05/16 22:43:11 by schoe            ###   ########.fr       */
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
int	ft_key_press(int keycode, t_map *map)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(map -> win.mlx, map -> win.img);
		mlx_destroy_window(map -> win.mlx, map -> win.mlx_win);
		exit(0);
	}
	if (keycode == LEFT)
    	map -> move_x -= 15;
  	if (keycode == RIGHT)
    	map -> move_x += 15;
  	if (keycode == UP && map -> move_y - 150 > -600)
   		map -> move_y -= 10;
  	if (keycode == DOWN && double_max(map -> rot.y, map) + 150 < 1440)
    	map -> move_y += 10;
    if (keycode == zoom_in)
	{
		map -> deg_x = -0.615472907;
		map -> deg_y = PI / 4;
		map -> deg_z = 0;
		if (double_max(map -> rot.y, map) * 1.2 < 1440)
    		map -> distance += 0.15;
	}
    if (keycode == zoom_out && map -> distance - 0.2 > 1)
    	map -> distance -= 0.2;
    ft_key_deg(keycode, map);
    ft_key_parallel(keycode, map);
	return (0);
}
