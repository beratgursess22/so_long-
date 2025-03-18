/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:31:21 by igurses           #+#    #+#             */
/*   Updated: 2025/02/25 15:10:13 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_prog *prog, int x, int y)
{
	if (x < 0 || x >= prog->map_x || y < 0 || y >= prog->map_y)
		return ;
	if (prog->fake_map[y][x] == '1' || prog->fake_map[y][x] == 'A'
		|| prog->fake_map[y][x] == 'E')
		return ;
	prog->fake_map[y][x] = 'A';
	flood_fill(prog, x, y - 1);
	flood_fill(prog, x, y + 1);
	flood_fill(prog, x - 1, y);
	flood_fill(prog, x + 1, y);
}

void	counter_map(char **map, t_prog *prog)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	prog->map_x = ft_strlen(map[0]) - 1;
	prog->map_y = i;
}

int	map_count(char *map_name, t_prog *prog)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nName is not true.\n");
		free_for_name(prog);
	}
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error\nMap is NULL\n");
		free_for_name(prog);
	}
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**map_read(char *map_name, t_prog *prog)
{
	char	*line;
	int		fd;

	prog->map = malloc(sizeof(char *) * (prog->map_size + 1));
	if (!prog->map)
		free_for_name(prog);
	prog->map[prog->map_size] = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile did not open.\n");
		free_for_name(prog);
	}
	prog->map_size = 0;
	line = get_next_line(fd);
	while (line)
	{
		prog->map[prog->map_size] = line;
		prog->map_size++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (prog->map);
}

char	**map_read_fake(char *map_name, t_prog *prog)
{
	char	*line;
	int		fd;

	prog->fake_map = malloc(sizeof(char *) * (prog->map_size + 1));
	if (!prog->fake_map)
		free_for_name(prog);
	prog->fake_map[prog->map_size] = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile did not open.\n");
		free_for_name(prog);
	}
	prog->map_size = 0;
	line = get_next_line(fd);
	while (line)
	{
		prog->fake_map[prog->map_size] = line;
		prog->map_size++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (prog->fake_map);
}
