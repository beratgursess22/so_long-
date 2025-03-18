/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:30:32 by igurses           #+#    #+#             */
/*   Updated: 2025/02/24 13:17:45 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_program_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	free_program(t_prog *prog)
{
	mlx_destroy_image(prog->mlx->mlx, prog->image->background_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->character_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->collection_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->exit_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->wall_image);
	free(prog->image);
	mlx_destroy_window(prog->mlx->mlx, prog->mlx->mlx_window);
	free_program_map(prog->map);
	free_program_map(prog->fake_map);
	mlx_destroy_display(prog->mlx->mlx);
	free(prog->mlx->mlx);
	free(prog->mlx);
	free(prog->player);
	free(prog->exit);
	free(prog);
	ft_printf("Closed the game.\n");
	exit(1);
}

int	free_program_for_win(t_prog *prog)
{
	mlx_destroy_image(prog->mlx->mlx, prog->image->background_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->character_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->collection_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->exit_image);
	mlx_destroy_image(prog->mlx->mlx, prog->image->wall_image);
	free(prog->image);
	mlx_destroy_window(prog->mlx->mlx, prog->mlx->mlx_window);
	free_program_map(prog->map);
	free_program_map(prog->fake_map);
	mlx_destroy_display(prog->mlx->mlx);
	free(prog->mlx->mlx);
	free(prog->mlx);
	free(prog->player);
	free(prog->exit);
	free(prog);
	ft_printf("You won the game.\n");
	exit(1);
}

void	free_for_not_yet_start(t_prog *prog)
{
	free_program_map(prog->map);
	free_program_map(prog->fake_map);
	free(prog->image);
	free(prog->mlx);
	free(prog->player);
	free(prog->exit);
	free(prog);
	exit(0);
}

int	free_for_name(t_prog *prog)
{
	free(prog->image);
	free(prog->mlx);
	free(prog->player);
	free(prog->exit);
	free(prog);
	exit(1);
}
