/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:04:04 by bel-bouz          #+#    #+#             */
/*   Updated: 2018/11/07 23:16:07 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				fun1(struct s_tetrim *tet, int p,
		int max, struct s_tetrim temp)
{
	int j;
	int z;

	tet[p] = decalx(tet[p], max);
	j = 0;
	z = moin_y(tet[p]);
	while (j < 4)
	{
		tet[p].pos[j].y = temp.pos[j].y - z;
		j++;
	}
}

int					fun2(struct s_tetrim *tet, int p, struct s_tetrim temp)
{
	int j;

	j = 0;
	while (j < 4)
	{
		tet[p].pos[j].x = temp.pos[j].x;
		tet[p].pos[j].y = temp.pos[j].y;
		j++;
	}
	return (1);
}

void				vide_lettre(char **tab, char lettre, int max)
{
	int row;
	int cas;

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

void				affiche_tet(struct s_tetrim *tet, int len)
{
	int			j;
	int			max;
	char		**tab;

	j = 0;
	if (len > 26)
	{
		ft_putendl("error");
		exit(0);
	}
	max = ft_sqrt(len * 4) + j;
	while (j < len)
	{
		if (tet[j].pos[3].x + 1 > max)
			max = tet[0].pos[3].x + 1;
		j++;
	}
	tab = init_tab(max);
	j = add_titris(tet, len, tab, max);
}

void				adapter(struct s_tetrim *tet, int len)
{
	int		i;
	int		j;
	int		k;

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
