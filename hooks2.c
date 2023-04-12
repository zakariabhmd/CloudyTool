/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 01:30:48 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/12 02:45:27 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (next_pos != '1')
		count(criminal);
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
	if (next_pos != '1')
		count(criminal);
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
	if (next_pos != '1')
		count(criminal);
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
	if (next_pos != '1')
		count(criminal);
	if (next_pos == 'E' && criminal->c == 0)
		exit(0);
}

void	count(t_savage *criminal)
{
	criminal->moves++;
	ft_printf("moves = %d\n", criminal->moves);
}
