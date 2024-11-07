#ifndef SO_LONG_H
# define SO_LONG_H
# define ERROR "Error\n"
# define SPACE '0'
# define WALL '1'
# define COLLEC 'C'
# define EXIT 'E'
# define POS 'P'

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_game
{
    mlx_t            *mlx;
    char            **map;
    int             pi;
    int             pj;
    mlx_image_t     *player;
    mlx_image_t     *wall;
    mlx_image_t     *exit;
    mlx_image_t     *flat;
    mlx_image_t     *collect;
    mlx_texture_t   *texture;
    int             moves;
    int             num_collect;
    int             col;
    int             row;
}   t_game;

void    init_game(char **argv, t_game *game);
void    init_png(t_game *game);
void    error_map(t_game *game);
void    print_map(t_game *game);

void	moves_exit(keys_t key, t_game *game, int i, int j);
void    moves_space_w_a(keys_t key, t_game *game, int i, int j);
void    moves_space_s_d(keys_t key, t_game *game, int i, int j);
void	cnt_moves(keys_t key, t_game *game);

void    do_moves_w(keys_t key, t_game *game);
void    do_moves_a(keys_t key, t_game *game);
void    do_moves_s(keys_t key, t_game *game);
void    do_moves_d(keys_t key, t_game *game);

int     error_char(t_game *game);
int     check_char(t_game *game, char c);
void    error_walls(t_game *game);
void    error_rect(t_game *game);
void    error_check_char(t_game *game);

void    free_game(t_game *game);
void	free_error(t_game *game);
void	hook(mlx_key_data_t keydata, t_game *game);
void    finish_game(t_game *game);
void    row_col(t_game *game);

#endif