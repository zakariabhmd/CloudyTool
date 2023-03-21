/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:39:21 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/02/24 22:56:22 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void reader(t_savage *criminal, int fd)
{
    char *str = get_next_line(fd);
    char *twile = malloc(1);
    while(str)
    {
        twile = ft_strjoin_get(twile, str);
        str = get_next_line(fd);
    }
    criminal.map = ft_split(twile, '\n');
}
int main(int ac, char **av)
{
    t_savage criminal;
    int fd = open(av[1], O_RDONLY);
    reader(criminal, fd);
}