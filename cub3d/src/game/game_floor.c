#include <cub.h>

t_color	game_render_ceil(t_game *game, int bufpos, t_pt campos,
		float fstop_diag)
{
	float		dist;
	t_vec		offset;
	t_pt		hitpos;
	t_color		col;

	col = CTRANSPARENT;
	dist = fabs(fstop_diag / campos.y * (game->pos.z + CAM_HEIGHT - 1));
	offset = vec_scale(vec_normalize(game->hit_buffer[bufpos].ray.dir),
			dist);
	hitpos = vec_add(offset, vec_from_vec3(&game->pos));
	if (map_get(&game->map, hitpos.x, hitpos.y) == '1')
		col = game->map.floor;
	return (col);
}

t_color	game_render_floor_ceil(t_game *game, float z)
{
	t_color		col;

	col = game->map.ceiling;
	if (z < 0)
		col = game->map.floor;
	return (col);
}
