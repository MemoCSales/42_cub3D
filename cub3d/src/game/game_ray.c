#include <cub.h>

/*
Finds all hits of the `ray` with world.
Returns list of hits sorted by distance
Hits can be both with walls or any other game objects.
In case of a wall hit, a hitrec's obj will be set to NULL;
*/
void	game_get_2d_hits(t_game *game, t_hitrec *hitlist, t_line ray)
{
	const t_line	ray_orig = ray;
	int				i;

	i = -1;
	while (1)
	{
		hitlist[++i] = map_ray_intersect(&game->map, &ray);
		hitlist[i].dist = pt_dist(&ray_orig.loc, &hitlist[i].hit);
		ray.loc = vec_add(hitlist[i].hit, vec_scale(ray.dir, RAY_MARCH_DELTA));
		if (!(isfinite(hitlist[i].dist) && i < MAXHITS))
			break ;
	}
}
