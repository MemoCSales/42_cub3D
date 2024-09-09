#include <cub.h>

void	map_grid_allocation(t_map *map, char *path)
{
	int		y;
	int		fd;
	char	*line;

	map_obj_allocation(map);
	fd = map_open_file(path);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (map_color_texture_check(line))
			map_store_textures_and_colors(map, line);
		else
			map_process_row(map, line, &y);
		free(line);
		line = get_next_line(fd);
	}
	map->grid[y] = NULL;
	close(fd);
}

void	map_obj_allocation(t_map *map)
{
	map->grid = map_calloc(map);
}

char	**map_calloc(t_map *map)
{
	map->grid = (char **)ft_calloc(map->height + 1, sizeof(char *));
	if (!map->grid)
		errexit(ERROR_8);
	return (map->grid);
}

char	**map_copy_allocation(t_map *map)
{
	int		i;
	char	**copy;

	i = 0;
	copy = (char **)ft_calloc(map->height + 1, sizeof(char *));
	if (!copy)
		errexit(ERROR_8);
	while (i < map->height)
	{
		copy[i] = (char *)ft_calloc(1, sizeof(char) * (map->width + 1));
		if (!copy[i])
			errexit(ERROR_8);
		ft_strlcpy(copy[i], map->grid[i], map->width + 1);
		i++;
	}
	return (copy);
}
