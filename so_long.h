/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:32:20 by igurses           #+#    #+#             */
/*   Updated: 2025/02/25 16:53:26 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# include "mlx_linux/mlx.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_image
{
	void		*wall_image;
	void		*collection_image;
	void		*character_image;
	void		*exit_image;
	void		*background_image;

}				t_image;

typedef struct s_position
{
	int			exit_x;
	int			exit_y;
	int			player_x;
	int			player_y;
}				t_position;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_window;

}				t_mlx;

typedef struct s_prog
{
	char		**map;
	char		**fake_map;
	int			map_x;
	int			map_y;
	t_mlx		*mlx;
	t_image		*image;
	t_position	*player;
	t_position	*exit;
	int			count;
	int			has_filled;
	int			move_count;
	int			map_size;
	int			i;
	int			j;
}				t_prog;

char			**map_read(char *map_name, t_prog *prog);
char			**map_read_fake(char *map_name, t_prog *prog);
void			counter_map(char **map, t_prog *prog);
void			condition_image(t_prog *prog);
void			init_prog(t_prog *prog);
void			init_image(t_prog *prog);
int				keycode_actions(int keycode, t_prog *prog);
void			find_character_position(t_prog *prog);
void			find_exit_position(t_prog *prog);
int				counter_check(t_prog *prog, char a);
int				check_error(int count, char a);
void			flood_fill(t_prog *prog, int x, int y);
char			*map_name_check(char *map_name);
int				check_exit(t_prog *prog);
int				is_map_line_one(t_prog *prog);
int				is_map_rectangular(t_prog *prog);
int				counter_check_two(t_prog *prog, char a);
void			init_map(t_prog *prog, char *map_name);
int				counter_element(t_prog *prog);
void			check_map_shape(t_prog *prog);
void			mlx_init_program(t_prog *prog);
void			init_player(t_prog *prog);
void			free_program_map(char **map);
int				free_program(t_prog *prog);
void			free_for_not_yet_start(t_prog *prog);
int				free_program_for_win(t_prog *prog);
int				free_for_name(t_prog *prog);
void			null_two(t_prog *prog);
void			null(t_prog *prog);
void			move_count(int keycode, t_prog *prog);
void			move_image(t_prog *prog);
int				map_count(char *map_name, t_prog *prog);
int				can_move(t_prog *prog, int keycode);
void			init_map_two(t_prog *prog);
void			put_image(t_prog *prog);
void			control_map(t_prog *prog);

#endif