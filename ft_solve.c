/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 00:34:03 by bel-bouz          #+#    #+#             */
/*   Updated: 2018/11/07 23:04:37 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				rec(struct s_tetrim *tet, int p, char **tab, int max)
{
	int					i;
	int					j;
	struct s_tetrim		temp;

	i = 4;
	j = 0;
	temp = tet[p];
	while (--i >= 0)
		if (tet[p].pos[i].x > max - 1 || tet[p].pos[i].y > max - 1)
			return (1);
		else if (tab[tet[p].pos[i].x][tet[p].pos[i].y] == '.')
			tab[tet[p].pos[i].x][tet[p].pos[i].y] = tet[p].lettre;
		else
		{
			vide_lettre(tab, tet[p].lettre, max);
			if (tet[p].pos[i].y < (max - 1))
				tet[p] = decaly(tet[p], max);
			else if (tet[p].pos[i].x < (max - 1) && !(j = 0))
				fun1(tet, p, max, temp);
			else if (tet[p].pos[i].x >= (max - 1)
					&& tet[p].pos[i].y >= (max - 1))
				return (fun2(tet, p, temp));
			i = 4;
		}
	return (0);
}

int				add_titris(struct s_tetrim *tet, int len, char **tab, int max)
{
	int					i;
	int					r;
	struct s_tetrim		temp[26];

	i = -1;
	while (++i < len)
		temp[i] = tet[i];
	i = 0;
	while (i < len)
		if ((r = rec(tet, i, tab, max)) == 0)
			i++;
		else if (r == 1)
		{
			tet[i] = temp[i];
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

void			inisial_solvevar(struct s_variable *solve)
{
	solve->x = -1;
	solve->y = 0;
	solve->bl = 1;
	solve->i_pos = 0;
	solve->decal_x = 0;
	solve->i_tet = 0;
	solve->i2 = 0;
	solve->decal_y = 0;
	solve->lettre = 'A';
}

void			ft_retour(char **matrix, struct s_variable *solve)
{
	if (matrix[solve->x][0] == '#' || matrix[solve->x][0] == '.')
	{
		if (solve->i2 == 3)
		{
			solve->i2 = 0;
			solve->bl = 1;
			solve->i_tet++;
			solve->i_pos = 0;
			solve->lettre++;
		}
		else
			solve->i2++;
	}
}

void			ft_solve(char **matrix)
{
	struct s_variable		solve;
	struct s_tetrim			tet[26];

	inisial_solvevar(&solve);
	while (matrix[++solve.x])
	{
		solve.y = -1;
		while (matrix[solve.x][++solve.y])
			if (matrix[solve.x][solve.y] == '#')
			{
				if (solve.bl == 1)
				{
					solve.decal_x = solve.i2;
					solve.decal_y = solve.y;
				}
				tet[solve.i_tet].lettre = solve.lettre;
				tet[solve.i_tet].pos[solve.i_pos].x = solve.i2 - solve.decal_x;
				tet[solve.i_tet].pos[solve.i_pos].y = solve.y - solve.decal_y;
				solve.bl = 0;
				solve.i_pos++;
			}
		ft_retour(matrix, &solve);
	}
	adapter(tet, solve.i_tet);
	affiche_tet(tet, solve.i_tet);
}
