#include <cub.h>

void	map_find_direction(t_map *map, char *line, int *flag, int y)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == 'N' || line[x] == 'S' || line[x] == 'E'
			|| line[x] == 'W')
		{
			(*flag)++;
			map->direction = line[x];
			map->spawn_x = x;
			map->spawn_y = y;
		}
		x++;
	}
}

void	map_process_row(t_map *map, char *line, int *y)
{
	int	i;

	map->grid[*y] = (char *)ft_calloc(map->width + 1, sizeof(char));
	if (!map->grid[*y])
		errexit(ERROR_8);
	map_last_new_line(line);
	i = 0;
	while (line[i] != '\0' && i < map->width)
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
			map->grid[*y][i] = '0';
		else
		{
			map->grid[*y][i] = line[i];
		}
		i++;
	}
	(*y)++;
}
