/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:26:32 by schoe             #+#    #+#             */
/*   Updated: 2022/05/16 13:09:40 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
void	ft_error(char *str)
{
	ft_printf("%s\n",str);
	exit(1);
}
void	arg_error(int ac, char **av)
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
	ft_free_double(str);
}
