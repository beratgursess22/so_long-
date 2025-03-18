/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:32:10 by igurses           #+#    #+#             */
/*   Updated: 2025/02/25 16:52:24 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_prog(t_prog *prog)
{
	prog->image = malloc(sizeof(t_image));
	if (!prog->image)
	{
		ft_printf("Error: Memory allocation failed!\n");
		free_program(prog);
	}
	prog->mlx = malloc(sizeof(t_mlx));
	if (!prog->mlx)
	{
		ft_printf("Error: Memory allocation failed!\n");
		free_program(prog);
	}
	prog->player = malloc(sizeof(t_position));
	if (!prog->player)
	{
		ft_printf("Error: Memory allocation failed!\n");
		free_program(prog);
	}
	prog->exit = malloc(sizeof(t_position));
	if (!prog->exit)
	{
		ft_printf("Error: Memory allocation failed!\n");
		free_program(prog);
	}
	null_two(prog);
}

void	null(t_prog *prog)
{
	prog->image = NULL;
	prog->map = NULL;
	prog->fake_map = NULL;
	prog->player = NULL;
	prog->exit = NULL;
	prog->mlx = NULL;
}

void	null_two(t_prog *prog)
{
	prog->image->background_image = NULL;
	prog->image->character_image = NULL;
	prog->image->collection_image = NULL;
	prog->image->exit_image = NULL;
	prog->image->wall_image = NULL;
	prog->count = 0;
	prog->move_count = 0;
	prog->map_x = 0;
	prog->map_y = 0;
	prog->map_size = 0;
	prog->has_filled = 0;
	prog->player->exit_x = 0;
	prog->player->exit_y = 0;
	prog->player->player_x = 0;
	prog->player->player_y = 0;
}

int	main(int argc, char *argv[])
{
	t_prog	*program;

	if (argc != 2)
	{
		ft_printf("Error\nNumber of argv have to be two.\n");
		exit(0);
	}
	program = (t_prog *)malloc(sizeof(t_prog));
	if (!program)
		exit(1);
	null(program);
	init_prog(program);
	init_map(program, argv[1]);
	init_map_two(program);
	mlx_init_program(program);
	init_image(program);
	mlx_hook(program->mlx->mlx_window, 17, 0, free_program, program);
	mlx_loop(program->mlx->mlx);
	return (0);
}
