/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:41:20 by bel-bouz          #+#    #+#             */
/*   Updated: 2018/11/07 20:43:46 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int						ft_sqrt(int x)
{
	int i;
	int result;

	i = 1;
	result = 1;
	if (x == 0 || x == 1)
		return (x);
	while (result <= x)
	{
		i++;
		result = i * i;
	}
	return (i - 1);
}

char					**init_tab(int row)
{
	int			i;
	int			j;
	char		**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * row + 1)))
		return (NULL);
	i = 0;
	while (i < row)
	{
		j = 0;
		tab[i] = ft_strnew(row + 1);
		while (j < row)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = 0;
		i++;
	}
	return (tab);
}

struct s_tetrim			decalx(struct s_tetrim tet, int max)
{
	int i;

	i = 3;
	while (i >= 0)
	{
		if (tet.pos[i].x < max - 1)
			tet.pos[i].x += 1;
		i--;
	}
	return (tet);
}

struct s_tetrim			decaly(struct s_tetrim tet, int max)
{
	int i;

	i = 3;
	while (i >= 0)
	{
		if (tet.pos[i].y < max - 1)
			tet.pos[i].y += 1;
		i--;
	}
	return (tet);
}

int						moin_y(struct s_tetrim tet)
{
	int i;
	int min;

	i = 0;
	min = tet.pos[0].y;
	while (i < 4)
	{
		if (min < tet.pos[i].y)
			min = tet.pos[i].y;
		i++;
	}
	return (min);
}
