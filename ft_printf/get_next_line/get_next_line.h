/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:39:08 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/02/24 22:52:35 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55555
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>

char	*ft_strjoin_get(char *str1, char *str2);
char	*get_next_line(int fd);
char	*mkas(char *str1);
char	*mos(char *str1);
int		ft_strchr_get(char *s, int c);
int		ft_strlen_get(char *str);

#endif
