#include <cub.h>
#include <mlx.h>

void	game_init_logic(t_game *game)
{
	game->pos = vec3(game->map.spawn_x + .5, game->map.spawn_y + .5, 0);
	game->mz = 0;
	game->rot = rot_fromchar(game->map.direction);
	ft_bzero(&game->input_state, 64);
}

void	game_init_camera(t_game *game)
{
	size_t	hl_size;
	size_t	hl_num;

	game->fov = M_PI / 2;
	game->upscale = GAME_UPSCALE;
	game->cam_width = CAM_WIDTH;
	game_calc_camera_params(game);
	hl_size = sizeof(t_column_data);
	hl_num = ceil(game->disp.width / (float)game->upscale);
	game->hit_buffer = ft_xmalloc(hl_size * hl_num);
}

t_objtype	map_char_to_objtype(char objchar)
{
	if (objchar == 'A')
		return (OBJ_AGENT);
	else if (objchar == 'P')
		return (OBJ_PHONEBOX);
	else if (objchar == 'R')
		return (OBJ_PILL);
	else if (objchar == 'D')
		return (OBJ_DOOR);
	return (OBJ_NONE);
}
