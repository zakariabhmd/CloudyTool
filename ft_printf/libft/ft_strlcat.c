/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 05:11:25 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/10/31 05:11:26 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	i;

	if (!dstsize)
		return (ft_strlen(src));
	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = 0;
	if (dstsize < d + 1)
		return (dstsize + s);
	if (dstsize > d + 1)
	{
		while (src[i] != '\0' && d + 1 + i < dstsize)
		{
			dst[d + i] = src[i];
			i++;
		}
	}
	dst[d + i] = '\0';
	return (d + s);
}
