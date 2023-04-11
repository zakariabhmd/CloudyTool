/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 00:18:01 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/11 01:31:53 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_items_help(t_savage *criminal)
{
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
	check_items_help2(criminal);
}

void	check_items_help2(t_savage *criminal)
{
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
	check_items_help(criminal);
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

void	main2(t_savage *criminal, int y, int x)
{
	check_len(criminal, y, x);
	check_num(criminal, y, x);
	check_items(criminal, y, x);
	check_error(criminal, y, x);
	valid_path(criminal, y, x);
}
