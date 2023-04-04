/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 05:12:10 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/10/31 05:12:11 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	find;
	size_t	zed;

	last = (char *)s;
	find = (char)c;
	zed = ft_strlen(s);
	while (zed > 0)
	{
		if (last[zed] == find)
			return (last + zed);
		zed--;
	}
	if (last[zed] == find)
		return (last);
	return (0);
}
