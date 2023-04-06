/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 05:20:27 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/05 06:02:06 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_dim get_player_position(t_savage *criminal)
{
	int idx1;
	int idx2;
	t_dim player_pos;

	player_pos.x = -1;
	player_pos.y = -1;

	idx1 = 0;
	while (criminal->map[idx1])
	{
		idx2 = 0;
		while (criminal->map[idx1][idx2])
		{
			if (criminal->map[idx1][idx2] == 'P')
			{
				player_pos.x = idx2;
				player_pos.y = idx1;
				return player_pos;
			}
			idx2++;
		}
		idx1++;
	}
	return player_pos;
}

char get_position_in_map(t_savage *criminal, t_dim *wanted_dim)
{
	char res;
	int idx1;
	int idx2;

	idx1 = 0;
	while (criminal->map[idx1])
	{
		idx2 = 0;
		while (criminal->map[idx1][idx2])
		{
			if (idx1 == wanted_dim->y && idx2 == wanted_dim->x)
				return (criminal->map[idx1][idx2]);
			idx2++;
		}
		idx1++;
	}

	return (res);
}

void modify_map(t_savage *criminal, t_dim *position, char with_what)
{
	int idx1 = 0;
	int idx2;

	while (criminal->map[idx1])
	{
		idx2 = 0;
		while (criminal->map[idx1][idx2])
		{
			if (idx1 == position->y && idx2 == position->x)
			{
				criminal->map[idx1][idx2] = with_what;
				return ;
			}
				// return (criminal->map[idx1][idx2]);
			idx2++;
		}
		idx1++;
	}


}

// int main ()
// {
// 	t_savage criminal;

// 	char *name = "zakaria bbahmiPd";
// 	char **nameSplited = ft_split(name, ' ');
// 	criminal.map = nameSplited;
// 	criminal.x = 0;
// 	criminal.y = 0;
// 	t_dim a;

// 	a.x = 6;
// 	a.y = 1;
// 	char p = get_position_in_map(&criminal, &a);
// 	printf("%c\n", p);
// 	// t_dim player_pos = get_player_position(&criminal);
// 	// printf("x: %d | y: %d\n" ,player_pos.x, player_pos.y);

// 	return (0);
// }