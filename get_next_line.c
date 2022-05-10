#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
char	*ft_get(ssize_t deep, int fd)
{
	char	*str;
	char	c;
	ssize_t	n;

	c = 0;
	n = read(fd, &c, 1);
	if (n < 0 || (n == 0 && deep == 0))
		return (NULL);
	if (c == '\n')
	{
		str = (char *)malloc(deep + 2);
		str[deep + 1] = '\0';
	}
	else if (c == '\0')
		str = (char *)malloc(deep + 1);
	else
		str = ft_get(deep + 1, fd);
	if (str)
		str[deep] = c;
	return (str);
}

char	*get_next_line(int fd)
{
	return (ft_get(0,fd));
}
