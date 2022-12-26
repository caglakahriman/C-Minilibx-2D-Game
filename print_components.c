#include "escape.h"

void	put_image(t_map *map, void *item, int x, int y)
{
	mlx_put_image_to_window(map->mlx, \
			map->window, item, x * 64, y * 64);
}

void	print_components(t_map *map, int x, int y)
{
	if (map->movecount > 0)
		ft_printf("%d\n", map->movecount);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->lines[y][x] == '1')
				put_image(map, map->img->wall, x, y);
			else if (map->lines[y][x] == 'P')
				put_image(map, map->img->player, x, y);
			else if (map->lines[y][x] == 'C')
				put_image(map, map->img->collectible, x, y);
			else if (map->lines[y][x] == 'E')
				put_image(map, map->img->exit, x, y);
			else if (map->lines[y][x] == '0')
				;
			else
				destroy_game(map);
			x++;
		}
		y++;
	}
	map->movecount++;
}
