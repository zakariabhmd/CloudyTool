/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:39:21 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/04/03 21:31:05 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s[a])
	{
		if (a >= start && b < len)
		{
			str[b] = s[a];
			b++;
		}
		a++;
	}
	str[b] = '\0';
	return (str);
}

int	counter(const char *tpm, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*tpm)
	{
		if (*tpm != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*tpm == c)
			count = 0;
		tpm++;
	}
	return (i);
}

int	size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	int		size;
	char	**sp;
	int		j;

	i = 0;
	j = -1;
	word = counter(s, c);
	sp = (char **)malloc((word + 1) * sizeof(char *));
	if (!sp)
		return (0);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = size_word(s, c, i);
		sp[j] = ft_substr(s, i, size);
		i += size;
	}
	sp[j] = 0;
	return (sp);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// ---------------------------------------------------------------------------------

void	check_error(t_savage *criminal, int y, int x)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i != y)
	{
		while (j != x - 1)
		{
			if (criminal->map[i][j] != '1' && criminal->map[i][j] != '0' && criminal->map[i][j] != 'P' && criminal->map[i][j] != 'E' && criminal->map[i][j] != 'C')
			{
				ft_printf("error");
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_map(char *len)
{
	int i;
	
	i = ft_strlen(len) - 1;
	if (len[i] != 'r')
		exit(1);
	if (len[i - 1] != 'e')
		exit(1);
	if(len[i - 2] != 'b')
		exit(1);
}

void check_items(t_savage *criminal, int y, int x)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	criminal->p = 0;
	criminal->c = 0;
	criminal->e = 0;
	while (i != y)
	{
		while (j != x)
		{
			if (criminal->map[i][j] == 'P')
				criminal->p++;
			if (criminal->map[i][j] == 'C')
				criminal->c++;
			if (criminal->map[i][j] == 'E')
				criminal->e++;
			j++;
		}
		i++;
		j = 0;
	}
	if (criminal->p == 0)
	ft_printf("makaynche player");
	if (criminal->c == 0)
	ft_printf("makaynche coins");
	if (criminal->e == 0)
	ft_printf("makayche exit");
}

void check_len(t_savage *criminal, int y, int x)
{
	int	i;
	
	i = 0;
	while (i != y)
	{
		if (x != ft_strlen(criminal->map[i])){
		ft_printf("tol maci hwa hadak");
			exit(1);
		}
		i++;
	}
}

void check_num(t_savage *criminal, int y, int x)
{
	int i;
	
	
	i = 0;
	while(i != x)
	{
		if(criminal->map[0][i] != '1')
		{
			ft_printf("maxi 1\n");
			exit(0);
		}
		if(criminal->map[y - 1][i] != '1')
		{
			ft_printf("maxi 1\n");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i != y)
	{
		if(criminal->map[i][0] != '1' || criminal->map[i][x - 1] != '1')
		{
			ft_printf("machi 1\n");
			exit(1);
		}
		i++;
	}
}

void  calyx(int *y, int *x, int fd)
{
	int i = 0;
	char	*str;
	
	while(i != 10)
	{
		str = get_next_line(fd);
		if(str == NULL)
			break ;
		if(str != NULL)
			(*x) = ft_strlen(str);
		(*y)++;
	}
	close(fd);

}

void reader(t_savage *criminal, int fd)
{
    char *str = get_next_line(fd);
	criminal->tol = ft_strlen(str)-1;
    char *twile = malloc(1);
    while(str)
    {
        twile = ft_strjoin_get(twile, str);
		criminal->lines++;
        str = get_next_line(fd);
    }
    criminal->map = ft_split(twile, '\n');
}

int main(int ac, char **av)
{
    t_savage criminal;
	int		x;
	int		y;

	x = 0;
	y = 0;
	check_map(av[1]);
    int fd = open(av[1], O_RDONLY);
	calyx(&criminal.y, &criminal.x, fd);
    int fd2 = open(av[1], O_RDONLY);
    reader(&criminal, fd);
	check_len(&criminal, criminal.y, criminal.x);
	check_num(&criminal, criminal.y, criminal.x);
	check_items(&criminal, criminal.y, criminal.x);
	check_error(&criminal, criminal.y, criminal.x);
// 	int idx = 0;
// 	while (criminal.map[idx])
// 	{
// 		printf("%s", criminal.map[idx]);
// 		printf("\n");
// 		idx++;
// 	}
}

// ---------------------------------------------------------

void init(t_savage *criminal){

	criminal->mlx = mlx_init();
	criminal->win = mlx_new_window(criminal->mlx,criminal->tol*32,criminal->lines*32,"lo3ba l3ajiba");
	
}