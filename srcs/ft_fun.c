/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:41:20 by bel-bouz          #+#    #+#             */
/*   Updated: 2018/11/10 16:28:32 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void		vide_lettre(char **tab, char lettre, int max)
{
	int	row;
	int	cas;

	row = 0;
	while (row < max)
	{
		cas = 0;
		while (cas < max)
		{
			if (tab[row][cas] == lettre)
				tab[row][cas] = '.';
			cas++;
		}
		row++;
	}
}

void		affiche_tet(t_tetrim *tet, int len)
{
	int				j;
	int				max;
	char			**tab;

	j = 0;
	if (len > 26)
	{
		ft_putendl("error");
		exit(0);
	}
	max = ft_sqrt(len * 4);
	while (j < len)
	{
		if (tet[j].pos[3].x + 1 > max)
			max = tet[0].pos[3].x + 1;
		j++;
	}
	tab = init_tab(max);
	j = add_titris(tet, len, tab, max);
}

void		adapter(t_tetrim *tet, int len)
{
	int			i;
	int			j;
	int			k;

	k = 0;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < 4)
		{
			if (tet[i].pos[j].y < 0)
			{
				k = 0;
				while (k < 4)
				{
					tet[i].pos[k].y++;
					k++;
					j = -1;
				}
			}
			j++;
		}
		i++;
	}
}

int			ft_sqrt(int x)
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

char		**init_tab(int row)
{
	int				i;
	int				j;
	char			**tab;

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
