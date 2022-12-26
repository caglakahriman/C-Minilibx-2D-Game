# C-Minilibx-2D-Game
A 2D game, created using Minilibx library of C

This project is a very small 2D game.
Its purpose is to make you work with textures, sprites,
and some other very basic gameplay elements.

You can start the game by compiling the code using 'make', then './escape maps/map.ber'.
You can create your own map by following correct maps features (at least 1 collectible, 1 exit, 1 player. Map should be surrounded with walls.)
You can play the game with W,A,S,D keys.
Player can't exit without collecting all collectibles.
You can create your own textures and implement them in the 'img' directory. The file extension should be xpm.

On this project I,
- handle [minilibx](https://qst0.github.io/ft_libgfx/man_mlx.html#:~:text=MiniLibX%20is%20an%20easy%20way,image%20and%20basic%20events%20management.) library,
- handle keyhooks,
- handle reading maps,
- handle rendering a 2D scene,
- handle gameplay elements,
- handle character movement,
- handle move count of the player,
- handle collision check,