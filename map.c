#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "fdf.h"
int	int_max(int *arr, t_map *map)
{
	int	i;
	int	temp;
	int	max;

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

int	int_min(int *arr, t_map *map)
{
	int	i;
	int	temp;
	int	min;

	i = 0;
	if (map -> x * map -> y == 1)
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

int	ft_map_len(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		ft_error("Error : non-existent map");
	while (str[i])
		i++;
	return (i);
}
void	map_error(char *fdf, t_map *map)
{
	char	*line;
	char	**split_line;
	int		i;
	int		y;
	int		fd;

	y = 0;
	i = 0;
	fd = open(fdf, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split_line = ft_split(line,' ');
		if (i == 0)
			i = ft_map_len(split_line);
		if (i != ft_map_len(split_line))
			ft_error("Error : map is not rectangle");
		y++;
		free(line);
		ft_free_double(split_line);
	}
	close(fd);
	map -> x = i;
	map -> y = y;
}

void	make_mapval(int	fd, t_map *map)
{
	char	*line;
	char	**split_line;
	int		y;
	int		x;
	int		i;

	i = 0;
	y = 0;
	while (y < map -> y)
	{
		x = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split_line = ft_split(line, ' ');
		while(x < map -> x)
		{
			map -> val[y][x] = ft_atoi(split_line[x]);
			map -> color[i++] = map -> val[y][x];
			x++;
		}
		y++;
		free(line);
		ft_free_double(split_line);
	}
}

void	get_color(t_map *map)
{
	int	i;
	int	max;
	int	min;

	i = 0;
	max = int_max(map -> color, map);
	min = int_min(map -> color, map);
	while (i < map -> x * map -> y)
	{
		if (map -> color[i] <= (max - min) / 4)
			map -> color[i] = create_trgb(0,0,0,255);
		else if (map -> color[i] <= (max - min) / 2)
			map -> color[i] = create_trgb(0,0,255,0);
		else if (map -> color[i] <= (max - min) / 4 * 3)
			map -> color[i] = create_trgb(0,255,0,0);
		else
			map -> color[i] = create_trgb(1,150,150,150);
		i++;
	}
}

void	map_parsing(char *fdf, t_map *map)
{
	int	i;
	int	fd;

	i = 0;
	map_error(fdf, map);
	fd = open(fdf, O_RDONLY);
	map -> val = (int **)malloc(sizeof(int *) * map -> y);
	map -> color = (int *)malloc(sizeof(int) * (map -> x * map -> y));
	if (!(map -> val) || !(map -> color))
		ft_error("Error : malloc fail");
	while (i < map -> y)
	{
		map -> val[i] = (int *)malloc(sizeof(int) * (map -> x));
		if (!(map -> val[i]))
			ft_error("Error : malloc fail");
		i++;
	}
	make_mapval(fd, map);
	get_color(map);
	close(fd);
	//아래는 전체적으로 초기화 하는 함수 파야할듯?
	map -> deg_x = -0.615472907;
	map -> deg_y = PI / 4;
	map -> deg_z = 0;
}
