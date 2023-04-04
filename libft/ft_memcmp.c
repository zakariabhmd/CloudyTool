/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 05:09:23 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/10/31 05:09:24 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*alpha;
	unsigned char	*beta;
	size_t			i;

	alpha = (unsigned char *) s1;
	beta = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (alpha[i] != beta[i])
			return (alpha[i] - beta[i]);
		i++;
	}
	return (0);
}
