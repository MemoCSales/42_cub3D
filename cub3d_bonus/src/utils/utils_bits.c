#include <cub.h>

void	set_bit(unsigned char *c, unsigned int i, int val)
{
	if (val == 1)
		*c |= (1 << i);
	else if (val == 0)
		*c &= ~(1 << i);
}

bool	get_bit(unsigned char c, unsigned int i)
{
	return (1 & (c >> i));
}
