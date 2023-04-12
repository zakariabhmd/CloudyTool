/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:53:15 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/12 02:46:52 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	items_help(t_savage *criminal)
{
	if (criminal->imgwall == NULL)
	{
		ft_printf("ERROR : chi haja machi hya hadik\n");
		exit (1);
	}
	if (criminal->imgcoin == NULL)
	{
		ft_printf("ERROR : chi haja machi hya hadik\n");
		exit (1);
	}
	if (criminal->imgplayer == NULL)
	{
		ft_printf("ERROR : chi haja machi hya hadik\n");
		exit (1);
	}
}

void	items_help2(t_savage *criminal)
{
	if (criminal->imgfloor == NULL)
	{
		ft_printf("ERROR : chi haja machi hya hadik\n");
		exit (1);
	}
	if (criminal->imgdoor == NULL)
	{
		ft_printf("ERROR : chi haja machi hya hadik\n");
		exit (1);
	}
}
