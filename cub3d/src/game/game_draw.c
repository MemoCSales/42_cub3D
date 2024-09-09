#include <cub.h>
#include <pthread.h>

void	game_render(t_game *game)
{
	int		x;

	x = 0;
	while (x < game->disp.width)
	{
		game_render_col(game, x, game->upscale);
		x += game->upscale;
	}
}

void	game_draw(t_game *game)
{
	game_draw_frame(game);
	display_update(&game->disp);
}
