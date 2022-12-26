#include "./mlx/mlx.h"
#include "escape.h"

void	exit_game(t_map *map, int isimg)
{
	int	i;

	i = 0;
	if (isimg == 0)
		ft_printf("Error\n");
	while (map->lines[i])
		free(map->lines[i++]);
	free(map->lines);
	free(map);
	exit(0);
}

void	check_topbottom(t_map *map, int j)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->lines[j][i] != '1')
			exit_game(map, 0);
		i++;
	}
}

void	check_walls(t_map *map)
{
	int	i;

	i = 0;
	check_topbottom(map, 0);
	check_topbottom(map, (map->height - 1));
	i = 1;
	while (i < map->height - 1)
	{
		if (map->lines[i][0] != '1' || map->lines[i][map->width - 1] != '1')
			exit_game(map, 0);
		i++;
	}
	detect_components(map);
}

void	check_map(t_map *map)
{
	int	i;
	int	line_count;
	int	line_length;

	line_count = 0;
	i = 0;
	while (map->lines[i])
		i++;
	line_count = i;
	i = 0;
	while (map->lines[0][i] != '\n' && map->lines[0][i] != '\0')
		i++;
	line_length = i;
	map->width = line_length;
	map->height = line_count;
	check_walls(map);
}

void	read_map(t_map *map, char *berfile)
{
	char	*result;
	char	*line;
	int		fd;

	extension(map, berfile);
	fd = open(berfile, O_RDONLY);
	if (fd < 0)
		free_map(map);
	line = get_next_line(fd, map);
	if (!line)
		free_map(map);
	result = ft_strdup("");
	while (1)
	{
		result = ft_strjoin(result, line);
		free(line);
		line = get_next_line(fd, map);
		if (!line)
			break ;
	}
	map->lines = ft_split(result, '\n');
	free(result);
	check_map(map);
}
