#include <cub.h>

void	map_line_check(char *line)
{
	char	*original_line;

	original_line = line;
	while (*line && *line == ' ')
		line++;
	if (line != original_line)
	{
		ft_memmove(original_line, line, ft_strlen(line));
		line = original_line;
	}
}

int	map_color_check(char **colors)
{
	int	i;

	i = 0;
	while (colors[i] != NULL)
	{
		if (ft_strncmp(colors[i], "-", 1) == 0)
			return (1);
		i++;
	}
	return (0);
}
