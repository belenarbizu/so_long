/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:42:44 by barbizu-          #+#    #+#             */
/*   Updated: 2022/10/24 13:22:09 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	print_map(t_game *game)
{
	int32_t	i;
	int32_t	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			mlx_image_to_window(game->mlx, game->flat, j * 30, i * 30);
			if (game->map[i][j] == WALL)
				mlx_image_to_window(game->mlx, game->wall, j * 30, i * 30);
			else if (game->map[i][j] == POS)
			{
				game->pi = i;
				game->pj = j;
			}
			else if (game->map[i][j] == EXIT)
				mlx_image_to_window(game->mlx, game->exit, j * 30, i * 30);
			else if (game->map[i][j] == COLLEC)
				mlx_image_to_window(game->mlx, game->collect, j * 30, i * 30);
		}
	}
	mlx_image_to_window(game->mlx, game->player, game->pj * 30, game->pi * 30);
}

void	error_map(t_game *game)
{
	int	valid_map;

	valid_map = 1;
	error_rect(game);
	valid_map = error_char(game);
	if (!valid_map)
	{
		write(1, ERROR "Caracteres erroneos\n", 26);
		free_error(game);
	}
	error_check_char(game);
	error_walls(game);
}

void	init_game(char **argv, t_game *game)
{
	char	*str;
	char	*temp;
	char	*big_str;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	big_str = ft_strdup("");
	str = get_next_line(fd);
	while (str)
	{
		temp = ft_strjoin(big_str, str);
		free(big_str);
		big_str = temp;
		free(str);
		str = get_next_line(fd);
	}
	game->map = ft_split(big_str, '\n');
	close(fd);
	free(str);
	free(big_str);
	game->moves = 0;
	game->num_collect = 0;
}

void	init_png(t_game *game)
{
	game->mlx = mlx_init(game->col * 30, game->row * 30, "game", true);
	game->texture = mlx_load_png("/Users/barbizu-/Downloads/dino.png");
	game->player = mlx_texture_to_image(game->mlx, game->texture);
	game->texture = mlx_load_png("/Users/barbizu-/Downloads/wall.png");
	game->wall = mlx_texture_to_image(game->mlx, game->texture);
	game->texture = mlx_load_png("/Users/barbizu-/Downloads/salida.png");
	game->exit = mlx_texture_to_image(game->mlx, game->texture);
	game->texture = mlx_load_png("/Users/barbizu-/Downloads/flat.png");
	game->flat = mlx_texture_to_image(game->mlx, game->texture);
	game->texture = mlx_load_png("/Users/barbizu-/Downloads/collectable.png");
	game->collect = mlx_texture_to_image(game->mlx, game->texture);
	mlx_delete_texture(game->texture);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		write(1, ERROR "Faltan argumentos\n", 24);
		return (0);
	}
	game = malloc(sizeof(t_game));
	init_game(argv, game);
	row_col(game);
	error_map(game);
	init_png(game);
	print_map(game);
	mlx_key_hook(game->mlx, (mlx_keyfunc)hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	return (0);
}
