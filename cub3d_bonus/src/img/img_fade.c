#include <cub.h>

void	img_green_fade(t_img *img)
{
	int		y;
	int		x;
	t_color	c;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			c = img_getpxl(img, x, y);
			if ((c & 0xff0000) >> 4 * 4 > 0x4d)
				c = CGREEN;
			c = col_lum(c, MATTEX_FADE);
			if ((0xff00 & c) <= MATTEX_BACK)
				c = MATTEX_BACK;
			img_putpxl(img, x, y, c);
			x++;
		}
		y++;
	}
}
