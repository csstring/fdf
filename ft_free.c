#include "fdf.h"

void	ft_free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i < 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

void	ft_error(const char *str)
{
	printf("%s\n", str);
	exit(1);
}
