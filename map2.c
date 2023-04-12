/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:12:45 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/12 03:21:09 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_num(t_savage *criminal, int y, int x)
{
	int	i;

	i = 0;
	while (i != x)
	{
		check_num_help(criminal, i, y);
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

void	check_num_help(t_savage *criminal, int i, int y)
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
}
