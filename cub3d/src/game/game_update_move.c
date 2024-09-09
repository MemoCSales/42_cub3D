#include <cub.h>
#include <sys/time.h>
#include <unistd.h>

bool	map_finrange(t_map *map, float x, float y)
{
	return (x >= 0 && x <= map->width && \
			y >= 0 && y <= map->height);
}

/// rotate player by `diff` (counter-clockwise)
void	game_rot(t_game *game, float diff)
{
	game->rot += diff;
	if (game->rot < 0)
		game->rot += M_PI * 2;
	if (game->rot >= 2 * M_PI)
		game->rot -= M_PI * 2;
}

// TODO: keep this distance to walls
/*
float diag =
	hypot(hypot(game->cam_width / 2, game->fstop), game->cam_height / 2);
*/
void	game_move(t_game *game, t_vec *dir)
{
	const t_pt	nxtpos = vec_add(vec(game->pos.x, game->pos.y), *dir);
	t_pt		tmp;

	tmp = vec(game->pos.x, nxtpos.y);
	if (map_finrange(&game->map, tmp.x, tmp.y))
		game->pos.y = nxtpos.y;
	tmp = vec(nxtpos.x, game->pos.y);
	if (map_finrange(&game->map, tmp.x, tmp.y))
		game->pos.x = nxtpos.x;
}

void	game_update_walk(t_game *game)
{
	t_vec		walkdir;
	const float	m = 0.12;

	walkdir = vec(0, 0);
	if (game_key_pressed(game, KEY_FORWARD))
		walkdir = vec_add(walkdir, vec(0, -1));
	if (game_key_pressed(game, KEY_BACKWARD))
		walkdir = vec_add(walkdir, vec(0, 1));
	if (game_key_pressed(game, KEY_SLIDELEFT))
		walkdir = vec_add(walkdir, vec(-1, 0));
	if (game_key_pressed(game, KEY_SLIDERIGHT))
		walkdir = vec_add(walkdir, vec(1, 0));
	if (vec_nonzero(&walkdir))
	{
		walkdir = vec_rotate(vec_scale(vec_normalize(walkdir), m), -game->rot);
		game_move(game, &walkdir);
	}
}

void	game_update_move(t_game *game)
{
	if (game_key_pressed(game, KEY_RIGHT))
		game_rot(game, -ROT_SPEED);
	if (game_key_pressed(game, KEY_LEFT))
		game_rot(game, ROT_SPEED);
}
