/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 05:11:07 by zbabahmi          #+#    #+#             */
/*   Updated: 2022/10/31 05:11:08 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*i;
	size_t	alpha;
	size_t	beta;

	beta = 0;
	alpha = ft_strlen(s1);
	i = (char *)malloc(sizeof(char) * (alpha) + 1);
	if (!i)
		return (0);
	while (beta < alpha)
	{
		i[beta] = s1[beta];
		beta++;
	}
	i[beta] = '\0';
	return (i);
}
