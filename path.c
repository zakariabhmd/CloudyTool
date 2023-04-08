/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:40:21 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/08 22:08:42 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void valid_path(t_savage *criminal, int y, int x)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("%c\n", criminal->map1[i][j]);
	printf("%d \n", y);
	while (i != y)
	{
		ft_printf("OK\n");
		while (criminal->map1[i][j])
		{
			if (criminal->map1[i - 1][j] != 'E' && criminal->map1[i - 1][j] != '1')
				criminal->map1[i - 1][j] = 'P';
			if (criminal->map1[i + 1][j] != 'E' && criminal->map1[i + 1][j] != '1')
				criminal->map1[i + 1][j] = 'P';
			if (criminal->map1[i][j - 1] != 'E' && criminal->map1[i][j - 1] != '1')
				criminal->map1[i][j - 1] = 'P';
			if (criminal->map1[i][j + 1] != 'E' && criminal->map1[i][j + 1] != '1')
				criminal->map1[i][j + 1] = 'P';
			j++;
		}
		i++;
		j = 0;
	}
	check_valid_path(criminal, y, x);
	exit_valid_path(criminal, y, x);
}

void check_valid_path(t_savage *criminal, int y, int x)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i != y)
	{
		while (j != x)
		{
			if (criminal->map1[i][j] == 'C')
				exit(1);
			j++;
		}
		i++;
		j = 0;
	}
}

void exit_valid_path(t_savage *criminal, int y, int x)
{
	int i;
	int j;
	int e;

	i = 0;
	j = 0;
	e = 0;
	while (i != y)
	{
		while (j != x)
		{
			if (criminal->map1[i][j] == 'E')
			{
				if (criminal->map1[i - 1][j] == 'P')
					e++;
				if (criminal->map1[i + 1][j] == 'P')
					e++;
				if (criminal->map1[i][j + 1] == 'P')
					e++;
				if (criminal->map1[i][j - 1] == 'P')
					e++;
				j++;
			}
			i++;
			j = 0;
		}
	}
	if (e == 0)
	{
		ft_printf("invalid path");
		exit(1);
	}
}