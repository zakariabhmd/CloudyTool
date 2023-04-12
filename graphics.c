/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:37:40 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/12 04:50:22 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialisation(t_savage *criminal)
{
	criminal->mlx = mlx_init();
	criminal->win = mlx_new_window(criminal->mlx, criminal->x * 32, \
	criminal->y * 32, "lo3ba l3ajiba");
	criminal->wall = "./items/wall.xpm";
	criminal->coin = "./items/coin.xpm";
	criminal->player = "./items/player.xpm";
	criminal->floor = "./items/floor.xpm";
	criminal->door = "./items/door.xpm";
	in2(criminal);
	ressam(criminal);
	mlx_hook(criminal->win, 2, 0, print_mouves, criminal);
	mlx_hook(criminal->win, 17, 0, ft_exit, criminal);
	mlx_loop(criminal->mlx);
}

void	ressam(t_savage *criminal)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < criminal->y)
	{
		while (x < criminal->x)
		{
			help_rassam2(criminal, y, x);
			help_rassam(criminal, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}

void	in2(t_savage *criminal)
{
	criminal->imgwall = mlx_xpm_file_to_image(criminal->mlx, \
	criminal->wall, &criminal->width, &criminal->height);
	criminal->imgcoin = mlx_xpm_file_to_image(criminal->mlx, \
	criminal->coin, &criminal->width, &criminal->height);
	criminal->imgplayer = mlx_xpm_file_to_image(criminal->mlx, \
	criminal->player, &criminal->width, &criminal->height);
	criminal->imgfloor = mlx_xpm_file_to_image(criminal->mlx, \
	criminal->floor, &criminal->width, &criminal->height);
	criminal->imgdoor = mlx_xpm_file_to_image(criminal->mlx, \
	criminal->door, &criminal->width, &criminal->height);
	items_help(criminal);
	items_help2(criminal);
}

void	help_rassam(t_savage *criminal, int y, int x)
{
	if (criminal->map[y][x] == 'E')
	{
		mlx_put_image_to_window(criminal->mlx, \
		criminal->win, criminal->imgdoor, x * 32, y * 32);
	}
	if (criminal->map[y][x] == 'P')
	{
		mlx_put_image_to_window(criminal->mlx, \
		criminal->win, criminal->imgplayer, x * 32, y * 32);
	}
	if (criminal->map[y][x] == 'C')
	{
		mlx_put_image_to_window(criminal->mlx, \
		criminal->win, criminal->imgcoin, x * 32, y * 32);
	}
}

void	help_rassam2(t_savage *criminal, int y, int x)
{
	if (criminal->map[y][x] == '1')
	{
		mlx_put_image_to_window(criminal->mlx, criminal->win, \
		criminal->imgwall, x * 32, y * 32);
	}
	if (criminal->map[y][x] == '0' || criminal->map[y][x] == 'E' \
	|| criminal->map[y][x] == 'P' || criminal->map[y][x] == 'C')
	{
		mlx_put_image_to_window(criminal->mlx, criminal->win, \
		criminal->imgfloor, x * 32, y * 32);
	}
}
