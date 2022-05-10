#include <stdio.h>
#include "libft.h"
void	ft_error(const char *str)
{
	printf("%s\n",str);
	exit(1);
}
int	arg_error(int ac, char **av)
{
	char	**str;
	int		i;

	i = 0;
	if (ac != 2)
		ft_error("Error : The number of input is wrong");
	str = ft_split(av[1] ,'.');
	while (str[i])
		i++;
	if (i != 2)
		ft_error("Error : wrong argc form");
	if (ft_strncmp(str[1], "fdf", 4) != 0)
		ft_error("Error : wrong argc form");
	return (1);
}
