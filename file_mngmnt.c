#include "escape.h"

void	extension(t_map *map, char *str)
{
	int	len;

	if (!str)
	{
		ft_printf("Error\n");
		free(map);
		exit(0);
	}
	len = ft_strlen(str);
	if (str[len - 1] != 'r' || str[len - 2] != 'e' || \
			str[len - 3] != 'b' || str[len - 4] != '.')
	{
		ft_printf("Error\n");
		free(map);
		exit(0);
	}
}

void	free_map(t_map *map)
{
	ft_printf("Error\n");
	free(map);
	exit(0);
}
