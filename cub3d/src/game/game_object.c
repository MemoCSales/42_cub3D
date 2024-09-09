#include <cub.h>

/// Calculate texture coordinates from world coordinates and wall direction
t_pt	mapwall_get_coord(int dir, t_pt3 *wcoord)
{
	double		i;
	const float	x = modf(wcoord->x, &i);
	const float	y = modf(wcoord->y, &i);

	if (dir == DWEST)
		return (vec(y, 1 - wcoord->z));
	else if (dir == DEAST)
		return (vec(1 - y, 1 - wcoord->z));
	else if (dir == DSOUTH)
		return (vec(x, 1 - wcoord->z));
	else if (dir == DNORTH)
		return (vec(1 - x, 1 - wcoord->z));
	return (vec(.5, .5));
}

t_color	wall_get_pixel(t_game *game, t_hitrec *hit, float z, int *past)
{
	int		dir;
	t_pt3	coord;
	t_pt	txtpos;
	t_color	col;

	if (z >= 0 && z <= 1)
	{
		dir = vec_direction(&hit->normal);
		coord = vec3_from_vec(&hit->hit);
		coord.z = z;
		txtpos = mapwall_get_coord(vec_direction(&hit->normal), &coord);
		col = img_getpxlr(&game->textures[dir], txtpos.x, txtpos.y);
		return (col);
	}
	else if (past)
		*past = 1 - 2 * (z < 0);
	return (CTRANSPARENT);
}
