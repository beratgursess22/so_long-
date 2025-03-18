/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:31:04 by igurses           #+#    #+#             */
/*   Updated: 2025/02/25 16:53:32 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_prog *prog)
{
	int	w;

	w = 64;
	prog->image->character_image = mlx_xpm_file_to_image(prog->mlx->mlx,
			"textures/char.xpm", &w, &w);
	if (!prog->image->character_image)
		ft_printf("Error: Character_image is not exist.\n");
	prog->image->wall_image = mlx_xpm_file_to_image(prog->mlx->mlx,
			"textures/wall.xpm", &w, &w);
	if (!prog->image->wall_image)
		ft_printf("Error: Wall_image is not exist.\n");
	prog->image->collection_image = mlx_xpm_file_to_image(prog->mlx->mlx,
			"textures/coins.xpm", &w, &w);
	if (!prog->image->collection_image)
		ft_printf("Error: Collecition_image is not exist.\n");
	prog->image->exit_image = mlx_xpm_file_to_image(prog->mlx->mlx,
			"textures/exits.xpm", &w, &w);
	if (!prog->image->exit_image)
		ft_printf("Error: Exit_image is not exist.\n");
	prog->image->background_image = mlx_xpm_file_to_image(prog->mlx->mlx,
			"textures/floor.xpm", &w, &w);
	if (!prog->image->background_image)
		ft_printf("Error: Background_image is not exist.\n");
	condition_image(prog);
}

void	condition_image(t_prog *prog)
{
	prog->i = -1;
	while (prog->map[++prog->i])
	{
		prog->j = -1;
		while (prog->map[prog->i][++prog->j]
			&& prog->map[prog->i][prog->j] != '\n')
			put_image(prog);
	}
}

void	put_image(t_prog *prog)
{
	mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window,
		prog->image->background_image, prog->j * 64, prog->i * 64);
	if (prog->map[prog->i][prog->j] == '1')
		mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window,
			prog->image->wall_image, prog->j * 64, prog->i * 64);
	if (prog->map[prog->i][prog->j] == 'P')
		mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window,
			prog->image->character_image, prog->j * 64, prog->i * 64);
	if (prog->map[prog->i][prog->j] == 'E')
		mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window,
			prog->image->exit_image, prog->j * 64, prog->i * 64);
	if (prog->map[prog->i][prog->j] == 'C')
		mlx_put_image_to_window(prog->mlx->mlx, prog->mlx->mlx_window,
			prog->image->collection_image, prog->j * 64, prog->i * 64);
}

void	move_image(t_prog *prog)
{
	mlx_clear_window(prog->mlx->mlx, prog->mlx->mlx_window);
	condition_image(prog);
}

void	control_map(t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	while (prog->map[i])
	{
		j = 0;
		while (prog->map[i][j] && prog->map[i][j] != '\n')
		{
			if (prog->map[i][j] == '0' || prog->map[i][j] == '1'
				|| prog->map[i][j] == 'P' || prog->map[i][j] == 'E'
				|| prog->map[i][j] == 'C')
				j++;
			else
			{
				ft_printf("Error\nInavlid character\n");
				free_for_not_yet_start(prog);
			}
		}
		i++;
	}
}
