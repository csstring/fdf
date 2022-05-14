int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;

	i = create_trgb(100, 50 ,50 ,5);
	printf("t: %d\n r: %d\n g :%d\n b : %d\n", get_t(i), get_r(i), get_g(i), get_b(i));
	return (0);
}*/
