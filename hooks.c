/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 06:43:38 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/10 01:37:26 by zbabahmi         ###   ########.fr       */
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

void	up(t_savage *criminal, t_dim player_pos, \
	t_dim wanted_pos, char next_pos)
{
	wanted_pos.x = player_pos.x;
	wanted_pos.y = player_pos.y - 1;
	next_pos = get_position_in_map(criminal, &wanted_pos);
	if (next_pos == '0')
	{
		modify_map(criminal, &player_pos, '0');
		modify_map(criminal, &wanted_pos, 'P');
		ressam(criminal);
	}
	if (next_pos == 'C')
	{
		criminal->c--;
		modify_map(criminal, &player_pos, '0');
		modify_map(criminal, &wanted_pos, 'P');
		ressam(criminal);
	}
	if (next_pos == 'E' && criminal->c == 0)
		exit(0);
}

void	left(t_savage *criminal, t_dim player_pos, \
	t_dim wanted_pos, char next_pos)
{
	wanted_pos.x = player_pos.x - 1;
	wanted_pos.y = player_pos.y;
	next_pos = get_position_in_map(criminal, &wanted_pos);
	if (next_pos == '0')
	{
		modify_map(criminal, &player_pos, '0');
		modify_map(criminal, &wanted_pos, 'P');
		ressam(criminal);
	}
	if (next_pos == 'C')
	{
		criminal->c--;
		modify_map(criminal, &player_pos, '0');
		modify_map(criminal, &wanted_pos, 'P');
		ressam(criminal);
	}
	if (next_pos == 'E' && criminal->c == 0)
		exit(0);
}

void	down(t_savage *criminal, t_dim player_pos, \
	t_dim wanted_pos, char next_pos)
{
	wanted_pos.x = player_pos.x;
	wanted_pos.y = player_pos.y + 1;
	next_pos = get_position_in_map(criminal, &wanted_pos);
	if (next_pos == '0')
	{
		modify_map(criminal, &player_pos, '0');
		modify_map(criminal, &wanted_pos, 'P');
		ressam(criminal);
	}
	if (next_pos == 'C')
	{
		criminal->c--;
		modify_map(criminal, &player_pos, '0');
		modify_map(criminal, &wanted_pos, 'P');
		ressam(criminal);
	}
	if (next_pos == 'E' && criminal->c == 0)
		exit(0);
}

void	right(t_savage *criminal, t_dim player_pos, \
	t_dim wanted_pos, char next_pos)
{
	wanted_pos.x = player_pos.x + 1;
	wanted_pos.y = player_pos.y;
	next_pos = get_position_in_map(criminal, &wanted_pos);
	if (next_pos == '0')
	{
		modify_map(criminal, &player_pos, '0');
		modify_map(criminal, &wanted_pos, 'P');
		ressam(criminal);
	}
	if (next_pos == 'C')
	{
		criminal->c--;
		modify_map(criminal, &player_pos, '0');
		modify_map(criminal, &wanted_pos, 'P');
		ressam(criminal);
	}
	if (next_pos == 'E' && criminal->c == 0)
		exit(0);
}
