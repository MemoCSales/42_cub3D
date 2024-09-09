#include <cub.h>

/*
	`past` will be set to
	-1 if hit is before object
	0 if hit
	1 if hit is after object
*/
t_color	obj_get_pixel(t_game *game, t_hitrec *hit, float z, int *past)
{
	return (wall_get_pixel(game, hit, z, past));
}
