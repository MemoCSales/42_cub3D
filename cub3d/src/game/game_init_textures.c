#include <cub.h>
#include <mlx.h>

int	game_init_textures(t_game *game)
{
	int		i;
	char	*txt;

	ft_bzero(game->textures, sizeof(t_img) * 4);
	i = -1;
	while (++i < 4)
	{
		txt = game->map.map_textures[i];
		if (access(txt, F_OK) != 0)
		{
			ft_putstr_fd(txt, STDERR_FILENO);
			game_deinit(game);
			errexit(": Texture file not accessible\n");
		}
		img_load(&game->textures[i], game->disp.mlx, txt);
	}
	return (OK);
}
