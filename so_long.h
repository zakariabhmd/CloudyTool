#ifndef SO_LONG_H
#define SO_LONG_H

#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include "./ft_printf/ft_printf.h"
#include <fcntl.h>
#include <mlx.h>

typedef struct s_savage
{
    void    *imgwall;
    void    *imgcoin;
    void    *imgplayer;
    void    *imgfloor;
    void    *imgdoor;
    void    *mlx;
    char    **map;
    int     x;
    int     y;
    int     p;
    int     e;
    int     c;
    int     width;
    int     height;
    int     tol;
    int     lines;
    void    *win;
    char    *wall;
    char    *coin;
    char    *player;
    char    *floor;
    char    *door;
}t_savage;


void initialisation(t_savage *criminal);
void ressam(t_savage *criminal);


#endif