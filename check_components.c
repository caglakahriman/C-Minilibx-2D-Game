#include "escape.h"

void	components(t_map *map)
{
	if ((map->exits == 0) || (map->players == 0) || (map->collectibles == 0))
		exit_game(map, 0);
}

void	detect_components(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->lines[y][x] == 'C')
				map->collectibles += 1;
			else if (map->lines[y][x] == 'E')
				map->exits += 1;
			else if (map->lines[y][x] == 'P')
			{
				map->players += 1;
				map->player_x = x;
				map->player_y = y;
			}
			x++;
		}
		y++;
	}
	components(map);
}
