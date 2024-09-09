#include <cub.h>

/* Exits printing `msg` */
void	errexit(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_game		game;

	if (argc != 2)
		errexit("Usage: ./cub3D <mapfile>\n");
	game_init(&game, argv[1], GAME_W, GAME_H);
	game_deinit(&game);
}
