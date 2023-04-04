/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 07:29:43 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/10/31 07:29:44 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *len)
{
	if (s == NULL)
		ft_putstr("(null)", len);
	while (s && *s)
	{
		ft_putchar(*s, len);
		s++;
	}
}
