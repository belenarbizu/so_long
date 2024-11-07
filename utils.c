/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:30:48 by barbizu-          #+#    #+#             */
/*   Updated: 2022/10/24 13:32:45 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_game(t_game *game)
{
	free(game->map);
	mlx_delete_image(game->mlx, game->player);
	mlx_delete_image(game->mlx, game->wall);
	mlx_delete_image(game->mlx, game->exit);
	mlx_delete_image(game->mlx, game->flat);
	mlx_delete_image(game->mlx, game->collect);
}

void	free_error(t_game *game)
{
	free(game->map);
	free(game);
	exit(0);
}

void	hook(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
	{
		mlx_close_window(game->mlx);
		free_game(game);
	}
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		do_moves_w(keydata.key, game);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		do_moves_a(keydata.key, game);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		do_moves_s(keydata.key, game);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		do_moves_d(keydata.key, game);
}

void	finish_game(t_game *game)
{
	free_game(game);
	mlx_close_window(game->mlx);
	ft_printf("----YOU WON!----\n");
}

void	row_col(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == COLLEC)
				game->num_collect++;
			j++;
		}
		i++;
	}
	game->row = i;
	game->col = j;
}
