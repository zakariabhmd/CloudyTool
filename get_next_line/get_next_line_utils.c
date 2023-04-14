/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 03:10:20 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/14 02:38:57 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_get(char *s, int c)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

int	ft_strlen_get(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_get(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*str;

	if (!str1)
	{
		str1 = malloc(1);
		str1[0] = '\0';
	}
	str = ((ft_strlen_get(str1) + ft_strlen_get(str2)) + 1);
	if (!str)
		return (0);
	i = 0;
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		str[i++] = str2[j++];
	str[i] = '\0';
	free (str1);
	return (str);
}

char	*mkas(char	*str1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (str1[i] != '\0' && str1[i] != '\n')
		i++;
	if (str1[i] == '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (0);
	j = 0;
	while (j < i)
	{
		str[j] = str1[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*mos(char *str1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (str1[i] != '\0' && str1[i] != '\n')
		i++;
	if (str1[i] == '\n')
		i++;
	str = malloc(ft_strlen_get(str1) - i + 2);
	if (!str)
		return (0);
	j = 0;
	while (str1[i])
		str[j++] = str1[i++];
	str[j] = '\0';
	return (str);
}
