#include <cub.h>
#include <pthread.h>

float	cam_coord_to_z(t_game *game, float dist, float cam_y, float fstop_diag)
{
	return (cam_y / fstop_diag
		* (fstop_diag + dist) + (CAM_HEIGHT + game->pos.z));
}

void	game_render_prep_col(t_game *game, int x, int w)
{
	int			i;
	int const	col = x / w;

	ft_bzero(&game->hit_buffer[col].hitlist, sizeof(t_hitrec) * (MAXHITS + 1));
	i = -1;
	while (++i < MAXHITS + 1)
		game->hit_buffer[col].hitlist[i].dist = INFINITY;
	game->hit_buffer[col].ray = game_ray_cast(game, (float)x
			/ game->disp.width);
	game_get_2d_hits(game, game->hit_buffer[col].hitlist,
		game->hit_buffer[col].ray);
}

t_color	game_render_pt(t_game *game, int bufpos, t_pt campos, float fstop_diag)
{
	float		z;
	int			i;
	t_color		col;

	col = CTRANSPARENT;
	i = 0;
	while (col == CTRANSPARENT && i < MAXHITS && \
		isfinite(game->hit_buffer[bufpos].hitlist[i].dist))
	{
		z = cam_coord_to_z(game, game->hit_buffer[bufpos].hitlist[i].dist,
				campos.y, fstop_diag);
		col = obj_get_pixel(game, &game->hit_buffer[bufpos].hitlist[i], z,
				NULL);
		i++;
	}
	z = cam_coord_to_z(game, game->hit_buffer[bufpos].hitlist[i].dist, campos.y,
			fstop_diag);
	if (game->pos.z + CAM_HEIGHT >= 1 && z < 1)
		col = col_apply(col, game_render_ceil(game, bufpos,
					campos, fstop_diag));
	if (col == CTRANSPARENT)
		col = game_render_floor_ceil(game, z);
	return (col);
}

void	game_render_col(t_game *game, int x, int w)
{
	t_pt	campos;
	float	fstop_diag;
	int		y;
	t_color	col;

	game_render_prep_col(game, x, w);
	campos.x = ((float)game->disp.width / 2 - x) / \
		game->disp.width * game->cam_width;
	fstop_diag = hypot(game->fstop, campos.x);
	y = 0;
	while (y < game->disp.height)
	{
		campos.y = ((float)game->disp.height / 2 - y) / game->disp.height \
			* game->cam_height;
		col = game_render_pt(game, x / w, campos, fstop_diag);
		img_draw_rect(&game->disp.buffer, ipt(x, y),
			ipt(x + w - 1, y + w - 1), col);
		y += w;
	}
}
