/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 05:10:59 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/10/31 05:11:00 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*zed;

	zed = (char *)s;
	while (*zed != (char)c)
	{
		if (*zed == '\0')
		{
			return (0);
		}
		zed++;
	}
	return (zed);
}
