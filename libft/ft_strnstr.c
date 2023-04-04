/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 05:12:01 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/10/31 05:12:02 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = 0;
	if (needle[i] == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[i] && i < len)
	{
		j = 0;
		a = i;
		while (haystack[a] == needle[j] && a < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
			a++;
		}
		i++;
	}
	return (0);
}
