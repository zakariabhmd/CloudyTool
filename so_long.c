/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:39:21 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/07 01:09:52 by zbabahmi         ###   ########.fr       */
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
		while (j != x - 1)
		{
			if (criminal->map[i][j] != '1' && criminal->map[i][j] != '0' && criminal->map[i][j] != 'P' && criminal->map[i][j] != 'E' && criminal->map[i][j] != 'C')
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
		exit (1);
	if (len[i - 1] != 'e')
		exit (1);
	if (len[i - 2] != 'b')
		exit (1);
}

void	check_items(t_savage *criminal, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	criminal->p = 0;
	criminal->c = 0;
	criminal->e = 0;
	while (i != y)
	{
		while (j != x)
		{
			if (criminal->map[i][j] == 'P')
				criminal->p++;
			if (criminal->map[i][j] == 'C')
				criminal->c++;
			if (criminal->map[i][j] == 'E')
				criminal->e++;
			j++;
		}
		i++;
		j = 0;
	}
	if (criminal->p == 0)
	{
		ft_printf("ERROR : makaynche player\n");
		exit (1);
	}
	if (criminal->p > 1)
	{
		ft_printf("ERROR : bzaf dyal player\n");
		exit (1);
	}
	if (criminal->c == 0)
	{
		ft_printf("ERROR : makaynche coins\n");
		exit (1);
	}
	if (criminal->e == 0)
	{
		ft_printf("ERROR : makaynche exit\n");
		exit (1);
	}
	if (criminal->e > 1)
	{
		ft_printf("ERROR : bzaf dyal exit\n");
		exit (1);
	}
}

void	check_len(t_savage *criminal, int y, int x)
{
	int	i;

	i = 0;
	while (i != y)
	{
		if (x != ft_strlen(criminal->map[i]))
		{
			ft_printf("ERROR : tol maci hwa hadak\n");
			exit (1);
		}
		i++;
	}
}

void	check_num(t_savage *criminal, int y, int x)
{
	int	i;

	i = 0;
	while (i != x)
	{
		if (criminal->map[0][i] != '1')
		{
			ft_printf("ERROR : maxi 1\n");
			exit (1);
		}
		if (criminal->map[y - 1][i] != '1')
		{
			ft_printf("ERROR : maxi 1\n");
			exit (1);
		}
		i++;
	}
	i = 0;
	while (i != y)
	{
		if (criminal->map[i][0] != '1' || criminal->map[i][x - 1] != '1')
		{
			ft_printf("ERROR : machi 1\n");
			exit (1);
		}
		i++;
	}
}

void	calyx(int *y, int *x, int fd)
{
	int		i;
	char	*str;

	i = 0;
	while (i != 10)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (str != NULL)
			(*x) = ft_strlen(str);
			(*y)++;
		if (x == y)
		exit (1);
	}
	close (fd);
}

void	reader(t_savage *criminal, int fd)
{
	char	*str = get_next_line(fd);
	criminal->tol = ft_strlen(str)-1;
	char	*twile = malloc(1);
	while (str)
	{
		twile = ft_strjoin_get(twile, str);
		criminal->lines++;
		str = get_next_line(fd);
	}
	criminal->map = ft_split(twile, '\n');
}

int	main(int ac, char **av)
{
	t_savage	criminal;
	int			x;
	int			y;

	x = 0;
	y = 0;
	check_map(av[1]);
	int fd = open(av[1], O_RDONLY);
	calyx(&criminal.y, &criminal.x, fd);
	int fd2 = open(av[1], O_RDONLY);
	reader(&criminal, fd);
	check_len(&criminal, criminal.y, criminal.x);
	check_num(&criminal, criminal.y, criminal.x);
	check_items(&criminal, criminal.y, criminal.x);
	check_error(&criminal, criminal.y, criminal.x);
	initialisation(&criminal);
}