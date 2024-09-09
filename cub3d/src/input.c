#include <cub.h>

bool	game_key_pressed(t_game *game, int kc)
{
	unsigned int	b;
	unsigned int	bt;

	b = kc / 8;
	bt = kc % 8;
	if (b >= INPUT_STATE_SIZE)
		return (false);
	return (get_bit(game->input_state[b], bt));
}

void	game_set_key(t_game *game, int kc, int state)
{
	unsigned int	b;
	unsigned int	bt;

	b = kc / 8;
	bt = kc % 8;
	if (b >= INPUT_STATE_SIZE)
		return ;
	set_bit(&game->input_state[b], bt, state);
}
