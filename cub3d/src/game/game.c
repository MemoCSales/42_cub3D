#include <cub.h>
#include <unistd.h>

/// Given the viewing plane width and FOV
/// calculates remaining camera parameters
void	game_calc_camera_params(t_game *game)
{
	game->fstop = game->cam_width / (tan(game->fov / 2) * 2);
	game->cam_height = (float)game->disp.height / game->disp.width
		* game->cam_width;
}

/// Update game logic for next frame
void	game_update(t_game *game)
{
	game_update_walk(game);
	game_update_move(game);
}

/// Given the x coordinate on the image plane, return the 2D ray for that column
t_line	game_ray_cast(t_game *game, float f)
{
	const float	angle = atan((-(-1 + 2 * f) * game->cam_width / 2) \
				/ game->fstop);
	t_line		ray;
	t_vec		perp;

	ray.dir = vec(-sin(game->rot + angle), -cos(game->rot + angle));
	ray.loc = vec_from_vec3(&game->pos);
	perp = vec_rotate(ray.dir, M_PI / 2);
	ray.loc = vec_add(ray.loc, vec_scale(perp, game->cam_width / 2 * (-1 + 2
					* f)));
	return (ray);
}

int	game_loop(t_game *game)
{
	game_draw(game);
	game_update(game);
	return (0);
}
