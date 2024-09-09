#include <cub.h>
#include <mlx.h>
#include <pthread.h>

void	game_deinit_textures(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
		img_deinit(&game->textures[i], game->disp.mlx);
}

/// Deinitialize game
void	game_deinit(t_game *game)
{
	mlx_do_key_autorepeaton(game->disp.mlx);
	if (game->map.height > 0)
		map_deinit(&game->map);
	game_deinit_textures(game);
	free(game->hit_buffer);
	display_deinit(&game->disp);
}
