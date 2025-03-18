/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:31:15 by igurses           #+#    #+#             */
/*   Updated: 2025/02/25 16:53:14 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_prog *prog, char *map_name)
{
	char	*ctrl;

	if (!map_name)
		free_program(prog);
	ctrl = map_name_check(map_name);
	if (!ctrl)
	{
		ft_printf("Error\nName is not true.\n");
		free_for_name(prog);
	}
	prog->map_size = map_count(map_name, prog);
	prog->map = map_read(map_name, prog);
	prog->fake_map = map_read_fake(map_name, prog);
	if (!(prog->map) || !(prog->fake_map))
	{
		ft_printf("Error\nName is not true.\n");
		free_for_name(prog);
	}
}

void	init_map_two(t_prog *prog)
{
	init_player(prog);
	counter_map(prog->map, prog);
	check_map_shape(prog);
	if (prog->has_filled == 0)
	{
		prog->has_filled = 1;
		flood_fill(prog, prog->player->player_x, prog->player->player_y);
		check_exit(prog);
	}
	control_map(prog);
}

int	counter_element(t_prog *prog)
{
	if (counter_check(prog, 'C') < 1)
	{
		ft_printf("Error.\nCollection's number is not enought.\n");
		free_for_not_yet_start(prog);
	}
	else if (counter_check(prog, 'P') != 1)
	{
		ft_printf("Error.\nPlayer's number is not one.\n");
		free_for_not_yet_start(prog);
	}
	else if (counter_check(prog, 'E') != 1)
	{
		ft_printf("Error.\nExit's number is not one.\n");
		free_for_not_yet_start(prog);
	}
	return (0);
}

void	check_map_shape(t_prog *prog)
{
	if (is_map_rectangular(prog) == 1)
	{
		ft_printf("Error.\nMap is not rectangular.\n");
		free_for_not_yet_start(prog);
	}
	if (is_map_line_one(prog) == 1)
	{
		ft_printf("Error.\nMap has not around one.\n");
		free_for_not_yet_start(prog);
	}
	counter_element(prog);
}

void	mlx_init_program(t_prog *prog)
{
	prog->mlx->mlx = mlx_init();
	if (!prog->mlx->mlx)
		free_program(prog);
	prog->mlx->mlx_window = mlx_new_window(prog->mlx->mlx, prog->map_x * 64,
			prog->map_y * 64, "So_Long");
	if (!prog->mlx->mlx_window)
		free_program(prog);
	mlx_key_hook(prog->mlx->mlx_window, keycode_actions, prog);
}
