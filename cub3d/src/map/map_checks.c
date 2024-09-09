#include <cub.h>

int	map_metadata_complete(t_map *map)
{
	return (map->map_textures[DNORTH] != NULL
		&& map->map_textures[DSOUTH] != NULL && map->map_textures[DEAST] != NULL
		&& map->map_textures[DWEST] != NULL && map->floor != CTRANSPARENT
		&& map->ceiling != CTRANSPARENT);
}

void	map_validation(t_map *map)
{
	char	**map_copy;

	map_copy = map_copy_allocation(map);
	if (!map_flood_fill(map, map_copy, map->spawn_x, map->spawn_y))
	{
		map_free_double_array(map_copy);
		errexit(ERROR_6);
	}
	map_free_double_array(map_copy);
	if (!map_metadata_complete(map))
		errexit(ERROR_7);
}

int	map_flood_fill(t_map *map, char **map_copy, int x, int y)
{
	if (!map_inrange(map, x, y) || map_copy[y][x] == ' ' || map_copy[y][x] == 0)
		return (0);
	if (ft_strchr(CHARS_BLOCKING, map_copy[y][x]) || map_copy[y][x] == 'V')
		return (1);
	if (!ft_strchr(CHARS_WALKABLE, map_copy[y][x]))
		return (0);
	map_copy[y][x] = 'V';
	return (map_flood_fill(map, map_copy, x - 1, y) && map_flood_fill(map,
			map_copy, x, y - 1) && map_flood_fill(map, map_copy, x + 1, y)
		&& map_flood_fill(map, map_copy, x, y + 1));
}

int	map_color_texture_check(char *line)
{
	const char	*prefixes[] = {"NO", "SO", "WE", "EA", "F", "C", \
							"\n", NULL};
	int			i;

	i = 0;
	while (prefixes[i] != NULL)
	{
		if (ft_strncmp(line, prefixes[i], ft_strlen(prefixes[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	map_metadata_add(t_map *map, char *line)
{
	const char	*prefixes[] = {"NO", "SO", "WE", "EA", "F", "C", \
							"\n", NULL};
	int			i;

	map_line_check(line);
	i = -1;
	while (prefixes[++i] != NULL)
	{
		if (ft_strncmp(line, prefixes[i], ft_strlen(prefixes[i])) == 0)
		{
			if (ft_strcmp(prefixes[i], "NO") == 0
				|| ft_strcmp(prefixes[i], "SO") == 0 || ft_strcmp(prefixes[i],
					"WE") == 0 || ft_strcmp(prefixes[i], "EA") == 0)
				map->txtcount++;
			return (1);
		}
	}
	return (0);
}
