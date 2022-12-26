#include "escape.h"

void	destroy_game(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img->collectible);
	mlx_destroy_image(map->mlx, map->img->player);
	mlx_destroy_image(map->mlx, map->img->exit);
	mlx_destroy_image(map->mlx, map->img->wall);
	free(map->img);
	exit_game(map, 1);
}