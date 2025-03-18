/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:30:45 by igurses           #+#    #+#             */
/*   Updated: 2025/02/15 17:30:46 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *putline)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(putline, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			free(putline);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		putline = ft_strjoin(putline, buff);
	}
	free(buff);
	return (putline);
}

char	*ft_put_line_main(char *putline)
{
	int		i;
	char	*str;

	i = 0;
	if (!putline[i])
		return (NULL);
	while (putline[i] && putline[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (putline[i] && putline[i] != '\n')
	{
		str[i] = putline[i];
		i++;
	}
	if (putline[i] == '\n')
	{
		str[i] = putline[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_put_remain(char *putline)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (putline[i] && putline[i] != '\n')
		i++;
	if (!putline[i])
	{
		free(putline);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(putline) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (putline[i])
		str[j++] = putline[i++];
	str[j] = '\0';
	free(putline);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*mainline;
	static char	*putline[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	putline[fd] = ft_read_line(fd, putline[fd]);
	if (!putline[fd] && !*putline[fd])
		return (NULL);
	mainline = ft_put_line_main(putline[fd]);
	putline[fd] = ft_put_remain(putline[fd]);
	return (mainline);
}
