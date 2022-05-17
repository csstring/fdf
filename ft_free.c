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
