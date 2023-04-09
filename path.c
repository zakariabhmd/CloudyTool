/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:40:21 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/09 03:14:54 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void valid_path(t_savage *criminal, int y, int x)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i != y)
	{
		while (j != x)
		{
			if (criminal->map1[i][j] == 'P')
			{
				if (criminal->map1[i][j - 1] != 'E' && criminal->map1[i][j - 1] != '1')
					criminal->map1[i][j - 1] = 'P';
				if (criminal->map1[i][j + 1] != 'E' && criminal->map1[i][j + 1] != '1')
					criminal->map1[i][j + 1] = 'P';
				if (criminal->map1[i + 1][j] != 'E' && criminal->map1[i + 1][j] != '1')
					criminal->map1[i + 1][j] = 'P';
				if (criminal->map1[i - 1][j] != 'E' && criminal->map1[i - 1][j] != '1')
					criminal->map1[i - 1][j] = 'P';
			}
			j++;
		}
		j = 0;
		i++;
	}
	check_valid_path(criminal, y, x);
	exit_valid_path(criminal, y, x);
	printf("okkkkkkay\n");
}

void check_valid_path(t_savage *criminal, int y, int x)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < criminal->y)
	{
		while (j < criminal->x)
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
				printf("okkkkkkay\n");
				if (criminal->map1[i - 1][j] == 'P')
					e++;
				if (criminal->map1[i + 1][j] == 'P')
					e++;
				if (criminal->map1[i][j + 1] == 'P')
					e++;
				if (criminal->map1[i][j - 1] == 'P')
					e++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (e == 0)
	{
		ft_printf("invalid path");
		exit(1);
	}
}