/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:41:17 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/10 02:44:16 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_savage
{
	void	*imgwall;
	void	*imgcoin;
	void	*imgplayer;
	void	*imgfloor;
	void	*imgdoor;
	void	*mlx;
	char	**map;
	char	**map1;
	int		x;
	int		y;
	int		p;
	int		e;
	int		c;
	int		width;
	int		height;
	int		tol;
	int		lines;
	void	*win;
	char	*wall;
	char	*coin;
	char	*player;
	char	*floor;
	char	*door;
}t_savage;

typedef struct s_dim
{
	int	x;
	int	y;
}t_dim;

t_dim	get_player_position(t_savage *criminal);
char	get_position_in_map(t_savage *criminal, t_dim *wanted_dim);
void	modify_map(t_savage *criminal, t_dim *position, char with_what);
void	initialisation(t_savage *criminal);
void	ressam(t_savage *criminal);
void	help(t_savage *criminal, int x, int y);
void	check_items_help2(t_savage *criminal);
void	hooks_help1(t_savage *criminal, t_dim wanted_pos, \
	t_dim player_pos, char next_pos);
int		ft_exit(void);
// --------------hooks----------------
void	up(t_savage *criminal, t_dim player_pos, \
	t_dim wanted_pos, char next_pos);
void	left(t_savage *criminal, t_dim player_pos, \
	t_dim wanted_pos, char next_pos);
void	down(t_savage *criminal, t_dim player_pos, \
	t_dim wanted_pos, char next_pos);
void	right(t_savage *criminal, t_dim player_pos, \
	t_dim wanted_pos, char next_pos);
int		print_mouves(int k, t_savage *criminal);
// ----------graphics---------------
void	initialisation(t_savage *criminal);
void	ressam(t_savage *criminal);
void	in2(t_savage *criminal);
void	help1(t_savage *criminal, int y, int x);
void	help2(t_savage *criminal, int y, int x);
int		ft_exit(void);
// ------------path------------------
void	valid_path(t_savage *criminal, int y, int x);
void	valid_path1(t_savage *criminal, int i, int j);
void	check_valid_path(t_savage *criminal, int y, int x);
void	exit_valid_path(t_savage *criminal, int y, int x);
void	exit_path(int e);

#endif
