#include <cub.h>

bool	is_transition(char from, char to)
{
	if (from == ' ' || !from)
		from = '0';
	if (to == ' ' || !to)
		to = '0';
	return ((from == '0' && to == '1') || \
		(from == '1' && to == '0'));
}

void	map_init_values(t_map *map)
{
	ft_bzero(map, sizeof(t_map));
	map->width = 0;
	map->height = 0;
	map->grid = NULL;
	map->spawn_x = 0;
	map->spawn_y = 0;
	map->direction = '\0';
	map->floor = CTRANSPARENT;
	map->ceiling = CTRANSPARENT;
	map->ceil_color.red = -1;
	map->ceil_color.green = -1;
	map->ceil_color.blue = -1;
	map->floor_color.red = -1;
	map->ceil_color.green = -1;
	map->ceil_color.blue = -1;
}

void	map_print(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		printf("%s\n", map->grid[y]);
		y++;
	}
}

void	map_direction_validation(char *line, int flag)
{
	if (flag != 1)
	{
		free(line);
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

int	map_open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		errexit(ERROR_9);
	return (fd);
}
