/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:31:32 by barbizu-          #+#    #+#             */
/*   Updated: 2022/10/24 13:31:36 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	do_moves_w(keys_t key, t_game *game)
{
	if (key == MLX_KEY_W && game->map[game->pi - 1][game->pj] != WALL)
	{
		cnt_moves(key, game);
		if (game->map[game->pi][game->pj] == EXIT)
		{
			if (game->num_collect == 0)
				finish_game(game);
			else
				moves_exit(key, game, game->pi, game->pj);
		}
		else if (game->map[game->pi][game->pj] == COLLEC)
		{
			game->num_collect--;
			game->map[game->pi + 1][game->pj] = SPACE;
			game->map[game->pi][game->pj] = SPACE;
			game->map[game->pi][game->pj] = POS;
			print_map(game);
		}
		else if (game->map[game->pi][game->pj] == SPACE)
		{
			moves_space_w_a(key, game, game->pi, game->pj);
			game->map[game->pi][game->pj] = POS;
			print_map(game);
		}
	}
}

void	do_moves_a(keys_t key, t_game *game)
{
	if (key == MLX_KEY_A && game->map[game->pi][game->pj - 1] != WALL)
	{
		cnt_moves(key, game);
		if (game->map[game->pi][game->pj] == EXIT)
		{
			if (game->num_collect == 0)
				finish_game(game);
			else
				moves_exit(key, game, game->pi, game->pj);
		}
		else if (game->map[game->pi][game->pj] == COLLEC)
		{
			game->num_collect--;
			game->map[game->pi][game->pj + 1] = SPACE;
			game->map[game->pi][game->pj] = SPACE;
			game->map[game->pi][game->pj] = POS;
			print_map(game);
		}
		else if (game->map[game->pi][game->pj] == SPACE)
		{
			moves_space_w_a(key, game, game->pi, game->pj);
			game->map[game->pi][game->pj] = POS;
			print_map(game);
		}
	}
}

void	do_moves_s(keys_t key, t_game *game)
{
	if (key == MLX_KEY_S && game->map[game->pi + 1][game->pj] != WALL)
	{
		cnt_moves(key, game);
		if (game->map[game->pi][game->pj] == EXIT)
		{
			if (game->num_collect == 0)
				finish_game(game);
			else
				moves_exit(key, game, game->pi, game->pj);
		}
		else if (game->map[game->pi][game->pj] == COLLEC)
		{
			game->num_collect--;
			game->map[game->pi - 1][game->pj] = SPACE;
			game->map[game->pi][game->pj] = SPACE;
			game->map[game->pi][game->pj] = POS;
			print_map(game);
		}
		else if (game->map[game->pi][game->pj] == SPACE)
		{
			moves_space_s_d(key, game, game->pi, game->pj);
			game->map[game->pi][game->pj] = POS;
			print_map(game);
		}
	}
}

void	do_moves_d(keys_t key, t_game *game)
{
	if (key == MLX_KEY_D && game->map[game->pi][game->pj + 1] != WALL)
	{
		cnt_moves(key, game);
		if (game->map[game->pi][game->pj] == EXIT)
		{
			if (game->num_collect == 0)
				finish_game(game);
			else
				moves_exit(key, game, game->pi, game->pj);
		}
		else if (game->map[game->pi][game->pj] == COLLEC)
		{
			game->num_collect--;
			game->map[game->pi][game->pj - 1] = SPACE;
			game->map[game->pi][game->pj] = SPACE;
			game->map[game->pi][game->pj] = POS;
			print_map(game);
		}
		else if (game->map[game->pi][game->pj] == SPACE)
		{
			moves_space_s_d(key, game, game->pi, game->pj);
			game->map[game->pi][game->pj] = POS;
			print_map(game);
		}
	}
}
