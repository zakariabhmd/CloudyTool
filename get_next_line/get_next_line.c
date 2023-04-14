/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 02:50:57 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/14 01:38:45 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*helper(char *likan, int fd)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = malloc(BUFFER_SIZE + 2);
	while (i != 0 && !(ft_strchr_get(likan, '\n')))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free (likan);
			free (buffer);
			likan = 0;
			return (0);
		}
		buffer[i] = '\0';
		likan = ft_strjoin_get(likan, buffer);
	}
	free (buffer);
	return (likan);
}

char	*get_next_line(int fd)
{
	static char	*likan;
	char		*str;
	char		*p;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	likan = helper(likan, fd);
	if (!likan)
		return (0);
	p = likan;
	if (likan[0] == '\0')
	{
		free (likan);
		likan = 0;
		return (0);
	}
	str = mkas(likan);
	likan = mos(likan);
	free (p);
	return (str);
}
