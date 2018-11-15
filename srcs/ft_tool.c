/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:04:04 by bel-bouz          #+#    #+#             */
/*   Updated: 2018/11/10 16:33:09 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void		decaly(t_tetrim *tet, int p, int max)
{
	int i;

	i = 3;
	while (i >= 0)
	{
		if (tet[p].pos[i].y < max - 1)
			tet[p].pos[i].y += 1;
		i--;
	}
}

int			fun2(t_tetrim *tet, int p, t_tetrim temp)
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

void		fun1(t_tetrim *tet, int p, int max, t_tetrim temp)
{
	int j;
	int i;
	int min;

	i = 3;
	while (i >= 0)
	{
		if (tet[p].pos[i].x < max - 1)
			tet[p].pos[i].x += 1;
		i--;
	}
	i = -1;
	min = tet[p].pos[0].y;
	while (++i < 4)
		if (min < tet[p].pos[i].y)
			min = tet[p].pos[i].y;
	j = -1;
	while (++j < 4)
		tet[p].pos[j].y = temp.pos[j].y - min;
}

int			rec(t_tetrim *tet, int p, char **tab, int max)
{
	int				i;
	int				j;
	t_tetrim		temp;

	i = 4;
	j = 0;
	ft_memcpy(&temp, &tet[p], sizeof(t_tetrim));
	while (--i >= 0)
		if (tet[p].pos[i].x > max - 1 || tet[p].pos[i].y > max - 1)
			return (1);
		else if (tab[tet[p].pos[i].x][tet[p].pos[i].y] == '.')
			tab[tet[p].pos[i].x][tet[p].pos[i].y] = tet[p].lettre;
		else
		{
			vide_lettre(tab, tet[p].lettre, max);
			if (tet[p].pos[i].y < (max - 1))
				decaly(tet, p, max);
			else if (tet[p].pos[i].x < (max - 1) && !(j = 0))
				fun1(tet, p, max, temp);
			else if (tet[p].pos[i].x >= (max - 1)
					&& tet[p].pos[i].y >= (max - 1))
				return (fun2(tet, p, temp));
			i = 4;
		}
	return (0);
}

int			add_titris(t_tetrim *tet, int len, char **tab, int max)
{
	int			i;
	int			r;
	t_tetrim	temp[26];

	i = -1;
	while (++i < len)
		ft_memcpy(&temp[i], &tet[i], sizeof(t_tetrim));
	i = 0;
	while (i < len)
		if ((r = rec(tet, i, tab, max)) == 0)
			i++;
		else if (r == 1)
		{
			ft_memcpy(&tet[i], &temp[i], sizeof(t_tetrim));
			if (i == 0)
			{
				max++;
				free(tab);
				tab = init_tab(max);
				i = 1;
			}
			i--;
		}
	affich_fin(tab);
	return (0);
}
