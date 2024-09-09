#include <cub.h>

void	map_deinit(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
		free(map->map_textures[i]);
	i = 0;
	if (map->grid == NULL)
		return ;
	while (map->grid[i] != NULL)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	map_deinit_doublepointer(char **dstr)
{
	int	i;

	i = -1;
	if (dstr == NULL)
		return ;
	while (dstr[++i] != NULL)
		free(dstr[i]);
	free(dstr);
	dstr = NULL;
}
