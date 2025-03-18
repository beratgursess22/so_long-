/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:31:27 by igurses           #+#    #+#             */
/*   Updated: 2025/02/23 18:02:05 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_character_position(t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	while (prog->map[i])
	{
		j = 0;
		while (prog->map[i][j])
		{
			if (prog->map[i][j] == 'P')
			{
				prog->player->player_x = j;
				prog->player->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_exit_position(t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	while (prog->map[i])
	{
		j = 0;
		while (prog->map[i][j])
		{
			if (prog->map[i][j] == 'E')
			{
				prog->exit->exit_x = j;
				prog->exit->exit_y = i;
			}
			j++;
		}
		i++;
	}
}

int	can_move(t_prog *prog, int keycode)
{
	if ((prog->map[prog->player->player_y][prog->player->player_x - 1] == '1'
		|| prog->map[prog->player->player_y][prog->player->player_x
		- 1] == 'E') && keycode == 97)
		return (0);
	if ((prog->map[prog->player->player_y - 1][prog->player->player_x] == '1'
		|| prog->map[prog->player->player_y
			- 1][prog->player->player_x] == 'E') && keycode == 119)
		return (0);
	if ((prog->map[prog->player->player_y + 1][prog->player->player_x] == '1'
		|| prog->map[prog->player->player_y
			+ 1][prog->player->player_x] == 'E') && keycode == 115)
		return (0);
	if ((prog->map[prog->player->player_y][prog->player->player_x + 1] == '1'
		|| prog->map[prog->player->player_y][prog->player->player_x
		+ 1] == 'E') && keycode == 100)
		return (0);
	return (1);
}

void	move_count(int keycode, t_prog *prog)
{
	if ((keycode == 97 && can_move(prog, 97) == 1) || (keycode == 119
			&& can_move(prog, 119) == 1) || (keycode == 115 && can_move(prog,
				115) == 1) || (keycode == 100 && can_move(prog, 100) == 1))
	{
		prog->move_count++;
		ft_printf("Number of Movement: %d \n", prog->move_count);
	}
}

void	init_player(t_prog *prog)
{
	find_character_position(prog);
	find_exit_position(prog);
}
