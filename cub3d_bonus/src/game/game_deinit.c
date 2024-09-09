#include <cub.h>
#include <mlx.h>
#include <pthread.h>

void	game_deinit_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < TXTMAX + 1 + game->map.txtcount - 4)
	{
		img_deinit(&game->textures[i], game->disp.mlx);
		i++;
	}
	free(game->textures);
}

/// Deinitialize game
void	game_deinit(t_game *game)
{
	mlx_do_key_autorepeaton(game->disp.mlx);
	if (game->map.height > 0)
		map_deinit(&game->map);
	img_deinit(&game->mattex, game->disp.mlx);
	game_deinit_textures(game);
	free(game->hit_buffer);
	free(game->mt.data);
	pthread_mutex_destroy(&game->mutex_render);
	display_deinit(&game->disp);
}

int	game_handle_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
