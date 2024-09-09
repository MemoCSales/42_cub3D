#include <cub.h>

void	game_draw_crosshairs(t_game *game)
{
	int const	cw = game->disp.width / 2;
	int const	ch = game->disp.height / 2;
	int const	stroke = fmax(game->disp.height / 500.0, 1);
	int const	size = game->disp.height / 50;

	img_draw_rect(&game->disp.buffer, ipt(cw - stroke / 2, ch - size),
		ipt(cw + stroke / 2, ch - size / 4), CGREEN);
	img_draw_rect(&game->disp.buffer, ipt(cw - stroke / 2, ch + size / 4),
		ipt(cw + stroke / 2, ch + size), CGREEN);
	img_draw_rect(&game->disp.buffer, ipt(cw - size, ch - stroke / 2),
		ipt(cw - size / 4, ch + stroke / 2), CGREEN);
	img_draw_rect(&game->disp.buffer, ipt(cw + size / 4, ch - stroke / 2),
		ipt(cw + size, ch + stroke / 2), CGREEN);
}

void	game_draw_frame(t_game *game)
{
	game_render(game);
	game_draw_crosshairs(game);
}
