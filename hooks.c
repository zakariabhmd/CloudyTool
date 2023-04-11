/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 06:43:38 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/11 01:30:36 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_mouves(int k, t_savage *criminal)
{
	t_dim	player_pos;
	t_dim	wanted_pos;
	char	next_pos;

	player_pos = get_player_position(criminal);
	if (k == 13)
	{
		up(criminal, player_pos, wanted_pos, next_pos);
	}
	if (k == 0)
	{
		left(criminal, player_pos, wanted_pos, next_pos);
	}
	if (k == 1)
	{
		down(criminal, player_pos, wanted_pos, next_pos);
	}
	if (k == 2)
	{
		right(criminal, player_pos, wanted_pos, next_pos);
	}
	if (k == 53)
		exit (0);
	return (0);
}

int	ft_exit(void)
{
	exit (0);
	return (0);
}
