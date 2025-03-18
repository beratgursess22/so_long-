/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:30:23 by igurses           #+#    #+#             */
/*   Updated: 2025/02/25 17:01:02 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_name_check(char *map_name)
{
	int	i;

	i = 0;
	i = ft_strlen(map_name);
	if (i < 4)
		return (NULL);
	if (map_name[i - 4] != '.' || map_name[i - 3] != 'b' || map_name[i
			- 2] != 'e' || map_name[i - 1] != 'r')
		return (NULL);
	return (map_name);
}

int	is_map_rectangular(t_prog *prog)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (prog->map[y])
	{
		x = 0;
		while (prog->map[y][x])
			x++;
		if (prog->map[y][x - 1] == '\n')
			x--;
		if (x != (prog->map_x))
		{
			ft_printf("Invalid map.\n");
			return (1);
		}
		y++;
	}
	return (0);
}

int	is_map_line_one(t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < prog->map_y)
	{
		if (prog->map[i][0] != '1' || prog->map[i][prog->map_x - 1] != '1')
		{
			ft_printf("Invalid map.\n");
			return (1);
		}
		i++;
	}
	while (j < prog->map_x)
	{
		if (prog->map[0][j] != '1' || prog->map[prog->map_y - 1][j] != '1')
		{
			ft_printf("Invalid map.\n");
			return (1);
		}
		j++;
	}
	return (0);
}

int	check_exit(t_prog *prog)
{
	int	collection_number;

	collection_number = counter_check_two(prog, 'C');
	if (prog->fake_map[prog->exit->exit_y + 1][prog->exit->exit_x] == 'A'
		&& collection_number == 0)
		return (1);
	else if (prog->fake_map[prog->exit->exit_y - 1][prog->exit->exit_x] == 'A'
		&& collection_number == 0)
		return (1);
	else if (prog->fake_map[prog->exit->exit_y][prog->exit->exit_x + 1] == 'A'
		&& collection_number == 0)
		return (1);
	else if (prog->fake_map[prog->exit->exit_y][prog->exit->exit_x - 1] == 'A'
		&& collection_number == 0)
		return (1);
	ft_printf("Error\nYou cannot acces to exit\n");
	ft_printf("or coin's number cannot collect at map\n");
	free_for_not_yet_start(prog);
	return (0);
}
