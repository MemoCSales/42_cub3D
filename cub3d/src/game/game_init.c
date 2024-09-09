#include <cub.h>
#include <mlx.h>
#include <pthread.h>

void	game_txt_load(t_game *game, int txtid, char *path)
{
	if (!img_load(&game->textures[txtid], game->disp.mlx, path))
	{
		game_deinit(game);
		errexit("Loading image failed\n");
	}
}

void	game_close(t_game *game)
{
	game_deinit(game);
	exit(EXIT_SUCCESS);
}

/// Set up mlx event hooks
void	game_init_hooks(t_game *game)
{
	mlx_hook(game->disp.win, KeyPress, KeyPressMask, game_keydown, game);
	mlx_hook(game->disp.win, KeyRelease, KeyReleaseMask, game_keyup, game);
	mlx_hook(game->disp.win, DestroyNotify, 0,
		(int (*)(void *))game_close, game);
	mlx_expose_hook(game->disp.win, (int (*)(void *))game_expose, game);
	mlx_loop_hook(game->disp.mlx, (int (*)(void *))game_loop, game);
}

/// Initialize new map - this needs to be called on map switch
void	game_init_map(t_game *game, char *map_path)
{
	ft_bzero(&game->map, sizeof(t_map));
	map_init_values(&game->map);
	map_read(&game->map, map_path);
	game_init_logic(game);
}

/// Initialize and run game
void	game_init(t_game *game, char *map_path, int w, int h)
{
	ft_bzero(game, sizeof(t_game));
	game_init_map(game, map_path);
	display_init(&game->disp, w, h);
	game_init_hooks(game);
	game_init_textures(game);
	game_init_logic(game);
	game_init_camera(game);
	mlx_loop(game->disp.mlx);
}
