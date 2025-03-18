/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:30:14 by igurses           #+#    #+#             */
/*   Updated: 2025/02/15 17:37:59 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_prog *prog, char **map)
{
	prog->count = counter_check(prog, 'C');
	if (map[prog->player->player_y][prog->player->player_x + 1] != '1')
	{
		if (map[prog->player->player_y][prog->player->player_x + 1] == 'E'
			&& prog->count == 0)
			free_program_for_win(prog);
		if (map[prog->player->player_y][prog->player->player_x + 1] != 'E')
		{
			map[prog->player->player_y][prog->player->player_x + 1] = 'P';
			map[prog->player->player_y][prog->player->player_x] = '0';
		}
	}
}

void	move_left(t_prog *prog, char **map)
{
	prog->count = counter_check(prog, 'C');
	if (map[prog->player->player_y][prog->player->player_x - 1] != '1')
	{
		if (map[prog->player->player_y][prog->player->player_x - 1] == 'E'
			&& prog->count == 0)
			free_program_for_win(prog);
		if (map[prog->player->player_y][prog->player->player_x - 1] != 'E')
		{
			map[prog->player->player_y][prog->player->player_x - 1] = 'P';
			map[prog->player->player_y][prog->player->player_x] = '0';
		}
	}
}

void	move_down(t_prog *prog, char **map)
{
	prog->count = counter_check(prog, 'C');
	if (map[prog->player->player_y + 1][prog->player->player_x] != '1')
	{
		if (map[prog->player->player_y + 1][prog->player->player_x] == 'E'
			&& prog->count == 0)
			free_program_for_win(prog);
		if (map[prog->player->player_y + 1][prog->player->player_x] != 'E')
		{
			map[prog->player->player_y + 1][prog->player->player_x] = 'P';
			map[prog->player->player_y][prog->player->player_x] = '0';
		}
	}
}

void	move_up(t_prog *prog, char **map)
{
	prog->count = counter_check(prog, 'C');
	if (map[prog->player->player_y - 1][prog->player->player_x] != '1')
	{
		if (map[prog->player->player_y - 1][prog->player->player_x] == 'E'
			&& prog->count == 0)
			free_program_for_win(prog);
		if (map[prog->player->player_y - 1][prog->player->player_x] != 'E')
		{
			map[prog->player->player_y - 1][prog->player->player_x] = 'P';
			map[prog->player->player_y][prog->player->player_x] = '0';
		}
	}
}

int	keycode_actions(int keycode, t_prog *prog)
{
	find_character_position(prog);
	if (keycode == 97)
	{
		move_count(keycode, prog);
		move_left(prog, prog->map);
	}
	if (keycode == 119)
	{
		move_count(keycode, prog);
		move_up(prog, prog->map);
	}
	if (keycode == 115)
	{
		move_count(keycode, prog);
		move_down(prog, prog->map);
	}
	if (keycode == 100)
	{
		move_count(keycode, prog);
		move_right(prog, prog->map);
	}
	if (keycode == 65307)
		free_program(prog);
	move_image(prog);
	return (0);
}
