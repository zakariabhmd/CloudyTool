/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 06:43:38 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/07 05:59:45 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int print_mouves(int k, t_savage *criminal)
{
	// printf("%s\n", criminal->map[0]);
	t_dim player_pos = get_player_position(criminal);
	t_dim wanted_pos;
	char next_pos;

	if (k == 13)
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
		// ft_printf("up\n");
	}
	if (k == 0)
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
		// ft_printf("left\n");
	}
	if (k == 1)
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
		// ft_printf("down\n");
	}
	if (k == 2)
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
		// ft_printf("right\n");
	}
	if (k == 53)
	exit (0);
	return (0);
}