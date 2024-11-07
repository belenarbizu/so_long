/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbizu- <barbizu-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:52:09 by barbizu-          #+#    #+#             */
/*   Updated: 2022/10/20 12:52:45 by barbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	error_char(t_game *game)
{
	int	i;
	int	j;
	int	valid_map;

	valid_map = 1;
	i = 0;
	while (game->map[i] && valid_map)
	{
		j = 0;
		while (game->map[i][j] && valid_map)
		{
			if (game->map[i][j] == SPACE || game->map[i][j] == WALL ||
				game->map[i][j] == COLLEC || game->map[i][j] == EXIT ||
				game->map[i][j] == POS)
				valid_map = 1;
			else
				valid_map = 0;
			j++;
		}
		i++;
	}
	return (valid_map);
}

int	check_char(t_game *game, char c)
{
	int	i;
	int	j;
	int	n;

	n = 0;
	i = 0;
	while (game->map[i] && !n)
	{
		j = 0;
		while (game->map[i][j] && !n)
		{
			if (game->map[i][j] == c)
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

void	error_walls(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if ((i == 0 && game->map[i][j] != WALL) || (j == 0
					&& game->map[i][j] != WALL) || (i == game->row - 1
					&& game->map[i][j] != WALL) || (j == game->col - 1
					&& game->map[i][j] != WALL))
			{
				write(1, ERROR "El mapa debe estar rodeado de muros\n", 42);
				free_error(game);
			}
		}
	}
}

void	error_rect(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			j++;
		}
		if (j != game->col)
		{
			write(1, ERROR "El mapa debe ser rectangular\n", 35);
			free_error(game);
		}
		i++;
	}
}

void	error_check_char(t_game *game)
{
	int	cnt;

	cnt = 0;
	cnt = check_char(game, EXIT);
	if (cnt < 1)
	{
		write(1, ERROR "Debe haber al menos una salida\n", 37);
		free_error(game);
	}
	cnt = check_char(game, POS);
	if (cnt != 1)
	{
		write(1, ERROR "Debe haber solo una posición inicial\n", 45);
		free_error(game);
	}
	cnt = check_char(game, COLLEC);
	if (cnt < 1)
	{
		write(1, ERROR "Debe haber al menos un objeto\n", 37);
		free_error(game);
	}
}
