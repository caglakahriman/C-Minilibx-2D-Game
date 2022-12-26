#include "escape.h"

void	imgs(t_map *imgs)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	imgs->img = malloc(sizeof(t_image));
	imgs->img->wall = mlx_xpm_file_to_image(imgs->mlx, WALL, &w, &h);
	imgs->img->player = mlx_xpm_file_to_image(imgs->mlx, PLAYER, &w, &h);
	imgs->img->collectible = mlx_xpm_file_to_image(imgs->mlx, COLLECT, &w, &h);
	imgs->img->exit = mlx_xpm_file_to_image(imgs->mlx, EXIT, &w, &h);
}

void	move(t_map *map, int movey, int movex)
{
	if (map->lines[map->player_y + movey][map->player_x + movex] == '0' || \
			map->lines[map->player_y + movey][map->player_x + movex] == 'C' || \
			map->lines[map->player_y + movey][map->player_x + movex] == 'E')
	{
		if (map->lines[map->player_y + movey][map->player_x + movex] == 'C')
			map->collectibles--;
		if (map->lines[map->player_y + movey][map->player_x + movex] == 'E')
		{
			if (map->collectibles == 0)
			{			
				mlx_destroy_window(map->mlx, map->window);
				destroy_game(map);
			}
			else
				return ;
		}
		map->lines[map->player_y][map->player_x] = '0';
		mlx_clear_window(map->mlx, map->window);
		map->lines[map->player_y + movey][map->player_x + movex] = 'P';
		map->player_y += movey;
		map->player_x += movex;
		print_components(map, 0, 0);
	}
}

int	movement(int keycode, t_map *map)
{
	if (keycode == 13)
		move(map, -1, 0);
	if (keycode == 0)
		move(map, 0, -1);
	if (keycode == 1)
		move(map, +1, 0);
	if (keycode == 2)
		move(map, 0, +1);
	else if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->window);
		destroy_game(map);
	}
	return (0);
}

int	xbutton(t_map *map)
{
	destroy_game(map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Error\n");
		exit(0);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		exit(0);
	map->movecount = 0;
	map->collectibles = 0;
	map->exits = 0;
	map->players = 0;
	read_map(map, argv[1]);
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, \
			map->width * 64, map->height * 64, "Escaping Hell");
	imgs(map);
	print_components(map, 0, 0);
	mlx_hook(map->window, 2, 1L << 0, &movement, map);
	mlx_hook(map->window, 17, 0, &xbutton, map);
	mlx_loop(map->mlx);
	return (0);
}
