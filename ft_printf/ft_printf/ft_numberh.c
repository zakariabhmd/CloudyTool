/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 07:26:41 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/10/31 07:26:42 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_numberh(unsigned int n, char c, int *len)
{
	unsigned int	base_max;
	char			*base;

	base_max = 16;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < base_max)
		ft_putchar(base[n % base_max], len);
	else
	{
		ft_numberh(n / base_max, c, len);
		ft_numberh(n % base_max, c, len);
	}
}
