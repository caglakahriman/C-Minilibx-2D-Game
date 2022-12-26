#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 100
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "./mlx/mlx.h"

typedef struct s_img
{
	void	*wall;
	void	*collectible;
	void	*player;
	void	*exit;
}				t_image;

typedef struct s_map
{
	char	**lines;
	char	*map;
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		movecount;
	int		collectibles;
	int		exits;
	int		players;
	t_image	*img;
}				t_map;

void	exit_game(t_map *map, int isimg);
void	extension(t_map *map, char *str);
void	destroy_game(t_map *map);
void	imgs(t_map *imgs);
void	free_map(t_map *map);
void	detect_components(t_map *map);
void	check_components(t_map *map);
void	check_topbottom(t_map *map, int j);
void	check_walls(t_map *map);
void	check_map(t_map *map);
void	read_map(t_map *map, char *berfile);
void	print_components(t_map *map, int x, int y);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd, t_map *map);
char	*update_buffer(char *buffer);
char	*next_line(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*next_line(char *buffer);
char	*update_buffer(char *buffer);
char	*ft_strchr(const char *s, int c);
int		isnlchar(char *buffer);
int		ft_strlen(char *s);
int		ft_printf(const char *str, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd, int *count);

# define PLAYER "./img/skull.xpm"
# define COLLECT "./img/heart.xpm"
# define EXIT "./img/exit.xpm"
# define WALL "./img/wall.xpm"

#endif
