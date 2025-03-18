/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:30:29 by igurses           #+#    #+#             */
/*   Updated: 2025/02/15 17:41:04 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counter_check(t_prog *prog, char a)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (prog->map[i])
	{
		j = 0;
		while (prog->map[i][j])
		{
			if (prog->map[i][j] == a)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	counter_check_two(t_prog *prog, char a)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (prog->fake_map[i])
	{
		j = 0;
		while (prog->fake_map[i][j])
		{
			if (prog->fake_map[i][j] == a)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
