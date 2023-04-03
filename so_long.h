#ifndef SO_LONG_H
#define SO_LONG_H

#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include "./ft_printf/ft_printf.h"
#include <fcntl.h>

# include <stdio.h>
#include <unistd.h>
#include <mlx.h>

typedef struct s_savage
{
    char    **map;
    int     x;
    int     y;
    int     p;
    int     e;
    int     c;
    int tol;
    int lines;
    void* mlx;
    void* win;
    char* wall;
    char* coin;
    char* player;
    char* floor;
    char* door;
    void* imgwall;
    void* imgcoin;
    void* imgplayer;
    void* imgfloor;
    void* imgdoor;
}t_savage;






#endif