/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:39:21 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/14 02:43:09 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error(t_savage *criminal, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != y)
	{
		while (j != x)
		{
			if (criminal->map[i][j] != '1' && criminal->map[i][j] != '0' \
			&& criminal->map[i][j] != 'P' && criminal->map[i][j] != 'E' \
			&& criminal->map[i][j] != 'C')
			{
				ft_printf("ERROR : makaynche 1 || 0 || P || E || C");
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_map(char *len)
{
	int	i;

	i = ft_strlen(len) - 1;
	if (len[i] != 'r')
	{
		ft_printf("ERROR : chi haja machi hya hadik\n");
		exit (1);
	}
	if (len[i - 1] != 'e')
	{
		ft_printf("ERROR : chi haja machi hya hadik\n");
		exit (1);
	}
	if (len[i - 2] != 'b')
	{
		ft_printf("ERROR : chi haja machi hya hadik\n");
		exit (1);
	}
	if (len[i - 3] != '.')
	{
		ft_printf("ERROR : chi haja machi hya hadik\n");
		exit (1);
	}
}

void	calyx(int *y, int *x, int fd)
{
	int		i;
	char	*str;

	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (str != NULL)
			(*x) = ft_strlen(str);
			(*y)++;
		free(str);
	}
	close (fd);
}

void	reader(t_savage *criminal, int fd)
{
	char	*str;
	char	*twile;
	int		i;

	i = 0;
	str = get_next_line(fd);
	twile = malloc(1);
	while (str)
	{
		twile = ft_strjoin_get(twile, str);
		free(str);
		str = get_next_line(fd);
	}
	criminal->map = ft_split(twile, '\n');
	criminal->map1 = ft_split(twile, '\n');
	free(twile);
	while (criminal->map[i])
		i++;
	if (i != criminal->y)
	{
		ft_printf("ERROR : chi haja machi hya hadik\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_savage	criminal;
	int			fd;
	int			fd2;

	if (ac == 1)
	{
		printf("chi haja machi hya hadik\n");
		exit (1);
	}
	check_map(av[1]);
	fd = open(av[1], O_RDONLY);
	calyx(&criminal.y, &criminal.x, fd);
	fd2 = open(av[1], O_RDONLY);
	reader(&criminal, fd2);
	main2(&criminal, criminal.y, criminal.x);
	initialisation(&criminal);
}
