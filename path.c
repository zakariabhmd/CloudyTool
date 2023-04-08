/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:40:21 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/08 05:36:13 by zbabahmi         ###   ########.fr       */
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
	// printf("%d \n", y);
	// while (i != y)
	// {
	// 	ft_printf("OK\n");
	// 	while (criminal->map1[i][j])
	// 	{
	// 		if (criminal->map1[i - 1][j] != 'E' && criminal->map[i - 1][j] != '1')
	// 			criminal->map1[i - 1][j] = 'P';
	// 		if (criminal->map1[i + 1][j] != 'E' && criminal->map[i + 1][j] != '1')
	// 			criminal->map1[i + 1][j] = 'P';
	// 		if (criminal->map1[i][j - 1] != 'E' && criminal->map[i][j - 1] != '1')
	// 			criminal->map1[i][j - 1] = 'P';
	// 		if (criminal->map1[i][j + 1] != 'E' && criminal->map[i][j + 1] != '1')
	// 			criminal->map1[i][j + 1] = 'P';
	// 		j++;
	// 	}
	// 	i++;
	// 	j = 0;
	// }
	// check_valid_path(criminal, y, x);
	// exit_valid_path(criminal, y, x);
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
	int h;

	i = 0;
	j = 0;
	h = 0;
	while (i != y)
	{
		while (j != x)
		{
			if (criminal->map1[i][j] == 'E')
			{
				if (criminal->map1[i - 1][j] == 'P')
					h++;
				if (criminal->map1[i + 1][j] == 'P')
					h++;
				if (criminal->map1[i][j + 1] == 'P')
					h++;
				if (criminal->map1[i][j - 1] == 'P')
					h++;
				j++;
			}
			i++;
			j = 0;
		}
	}
	if (h == 0)
	{
		ft_printf("invalid path");
		exit(1);
	}
}