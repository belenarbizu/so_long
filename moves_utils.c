/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:06:55 by barbizu-          #+#    #+#             */
/*   Updated: 2022/10/25 11:41:11 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	moves_exit(keys_t key, t_game *game, int i, int j)
{
	if (key == MLX_KEY_W)
	{
		game->map[i + 1][j] = SPACE;
		print_map(game);
		mlx_image_to_window(game->mlx, game->player, j * 30, i * 30);
	}
	else if (key == MLX_KEY_A)
	{
		game->map[i][j + 1] = SPACE;
		print_map(game);
		mlx_image_to_window(game->mlx, game->player, j * 30, i * 30);
	}
	else if (key == MLX_KEY_S)
	{
		game->map[i - 1][j] = SPACE;
		print_map(game);
		mlx_image_to_window(game->mlx, game->player, j * 30, i * 30);
	}
	else if (key == MLX_KEY_D)
	{
		game->map[i][j - 1] = SPACE;
		print_map(game);
		mlx_image_to_window(game->mlx, game->player, j * 30, i * 30);
	}
}

void	moves_space_w_a(keys_t key, t_game *game, int i, int j)
{
	if (key == MLX_KEY_W)
	{
		if (game->map[i + 1][j] == EXIT)
			mlx_image_to_window(game->mlx, game->exit, j * 30, i * 30);
		else
			game->map[i + 1][j] = SPACE;
	}
	else if (key == MLX_KEY_A)
	{
		if (game->map[i][j + 1] == EXIT)
			mlx_image_to_window(game->mlx, game->exit, j * 30, i * 30);
		else
			game->map[i][j + 1] = SPACE;
	}
}

void	moves_space_s_d(keys_t key, t_game *game, int i, int j)
{
	if (key == MLX_KEY_S)
	{
		if (game->map[i - 1][j] == EXIT)
			mlx_image_to_window(game->mlx, game->exit, j * 30, i * 30);
		else
			game->map[i - 1][j] = SPACE;
	}
	else if (key == MLX_KEY_D)
	{
		if (game->map[i][j - 1] == EXIT)
			mlx_image_to_window(game->mlx, game->exit, j * 30, i * 30);
		else
			game->map[i][j - 1] = SPACE;
	}
}

void	cnt_moves(keys_t key, t_game *game)
{
	if (key == MLX_KEY_W)
		game->pi--;
	else if (key == MLX_KEY_A)
		game->pj--;
	else if (key == MLX_KEY_S)
		game->pi++;
	else if (key == MLX_KEY_D)
		game->pj++;
	game->moves++;
	ft_printf("Moves: %i\n", game->moves);
}
