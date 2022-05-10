#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "fdf.h"
char	*get_next_line(int fd);
void	ft_free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

void	ft_error(const char *str)
{
	printf("%s\n",str);
	exit(1);
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
	map->x = i;
	map->y = y;
}

void	make_mapval(int	fd, t_map *map)
{
	char	*line;
	char	**split_line;
	int		i;
	int		x;

	i = 0;
	while (i < map -> y)
	{
		x = 0;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split_line = ft_split(line, ' ');
		while(x < map -> x)
		{
			map -> val[i][x] = ft_atoi(split_line[x]);
			x++;
		}
		i++;
		free(line);
		ft_free_double(split_line);
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
	if (!(map -> val))
		ft_error("Error : malloc fail");
	while (i < map -> y)
	{
		map -> val[i] = (int *)malloc(sizeof(int) * (map -> x));
		if (!(map -> val[i]))
			ft_error("Error : malloc fail");
		i++;
	}
	make_mapval(fd, map);
	close(fd);
}
