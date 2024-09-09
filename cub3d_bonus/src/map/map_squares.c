#include <cub.h>

bool	map_inrange(t_map *map, int x, int y)
{
	return (!((x < 0 || x >= map->width || y < 0 || y >= map->height)));
}

char	map_get(t_map *map, int x, int y)
{
	if (!map_inrange(map, x, y))
		return ('\0');
	return (map->grid[y][x]);
}

void	map_set(t_map *map, int x, int y, char c)
{
	if (!map_inrange(map, x, y))
		return ;
	map->grid[y][x] = c;
}
