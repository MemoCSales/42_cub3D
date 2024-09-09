#include <cub.h>
#include "vector.h"

void	game_keydown_controls(t_game *game, int key)
{
	if (key == KEY_EXIT1 || key == KEY_EXIT2)
		mlx_loop_end(game->disp.mlx);
}

int	game_keydown(int key, t_game *game)
{
	game_set_key(game, key, 1);
	game_keydown_controls(game, key);
	return (0);
}

int	game_keyup(int key, t_game *game)
{
	game_set_key(game, key, 0);
	return (0);
}
