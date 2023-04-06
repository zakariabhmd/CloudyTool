/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 05:09:59 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/10/31 05:10:00 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int bache, size_t ch7al)
{
	size_t			i;
	unsigned char	*z;

	z = (unsigned char *) b;
	i = 0;
	while (i < ch7al)
	{
		z[i] = (unsigned char) bache;
		i++;
	}
	return (b);
}
