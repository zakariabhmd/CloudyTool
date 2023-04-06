/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 07:26:47 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/10/31 07:26:55 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check(va_list list, const char c, int *len)
{
	if (c == 'c')
		ft_putchar((char)va_arg(list, int), len);
	else if (c == '%')
		ft_putchar(c, len);
	else if (c == 's')
		ft_putstr(va_arg(list, char *), len);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(list, int), len);
	else if (c == 'x' || c == 'X')
		ft_numberh(va_arg(list, int), c, len);
	else if (c == 'u')
		ft_putnbr_uns(va_arg(list, unsigned int), len);
	else if (c == 'p')
		ft_adresse(va_arg(list, void *), len);
}

int	ft_printf(const char *c, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, c);
	while (*c)
	{
		if (*c == '%')
		{
			c++;
			check(args, *c, &i);
		}
		else
			ft_putchar(*c, &i);
		c++;
	}
	va_end(args);
	return (i);
}
