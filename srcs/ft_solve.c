/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 00:34:03 by bel-bouz          #+#    #+#             */
/*   Updated: 2018/11/09 17:18:27 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void			inisial_solvevar(t_variable *solve)
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

void			ft_retour(char **matrix, t_variable *solve)
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
	t_variable			solve;
	t_tetrim			tet[26];

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
