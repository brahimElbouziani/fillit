/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:06:50 by mfilahi           #+#    #+#             */
/*   Updated: 2018/11/05 20:34:48 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	while (i < nb / 2 && i < 46340)
	{
		if ((i * i) == nb)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
void afficher(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n",tab[i]);
		i++;
	}
	printf("\n");
}
char **init_tab(int row)
{
	int	i;
	int j;
	char **tab;

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
////////////////////////////  solve ////// //////
struct tetrim 	decalx(struct tetrim tet, int max)
{
	int i;
	i = max - 1;
	while (i >= 0)
	{
		if (tet.pos[i].x < max - 1)
			tet.pos[i].x += 1;
		i--;
	}
	return (tet);
}
struct tetrim decaly(struct tetrim tet,int max)
{
	int i;
	i = max - 1;
	while (i >= 0)
	{	
		if (tet.pos[i].y < max - 1)
			tet.pos[i].y += 1;
		//		return (NULL);
		i--;
	}
	return (tet);
}


void vide_lettre(char **tab, char lettre,int max)
{
	int row;
	int cas;

	row = 0;
	while (row < max)
	{
		cas = 0;
		while(cas < max)
		{
			if (tab[row][cas] == lettre)
				tab[row][cas] = '.';
			cas++;
		}
		row++;
	}
}

/////////////recresuvite 
int		rec(struct tetrim *tet,int p,char **tab, int max)
{
	int i;
//	int r;
//	int a = 0;
//	int b = 0;
	int j;
	struct tetrim temp;

	i = 3;
	j = 0;
	temp = tet[p];

	while (i >= 0)
	{
		if (max == 5)
		{
			afficher(tab);
		}
		
		if ( ft_isalpha(tab[tet[p].pos[i].x][tet[p].pos[i].y]) == 0)
		{
			tab[tet[p].pos[i].x][tet[p].pos[i].y] = tet[p].lettre;
			afficher(tab);
		//	sleep(1);
		}
		else
		{
			vide_lettre(tab,tet[p].lettre,max);
			if (tet[p].pos[i].y != (max - 1))
			{
				tet[p] = decaly(tet[p], max);
			}
			else if (tet[p].pos[i].x != (max - 1))
			{
				tet[p]= decalx(tet[p], max);
				while (j < 4)
				{
					tet[p].pos[j].y = temp.pos[j].y;
					j++;
				}
			}
			if (tet[p].pos[i].x == (max - 1) && tet[p].pos[i].y == (max - 1) )
			{
			//r= -1;
			//while(++r < max)
		//		printf("tet[%d].pos[%d].x = %d || tet[%d].pos[%d].y = %d \n",p,i,tet[p].pos[i].x,p,i,tet[p].pos[i].y);

				j = 0;
				while (j < 4)
				{
					tet[p].pos[j].x = temp.pos[j].x;
					tet[p].pos[j].y = temp.pos[j].y;
					j++;
				}
				vide_lettre(tab,tet[p].lettre,max);
				return (1);
			}
			i = 4;
			j = 0;
		}
		i--;
	}
	return (0);
}


int			add_titris(struct tetrim *tet,int len,char **tab)
{
	int i;
	int max;
	int r;
	struct tetrim temp[26];
	int j;
	j = 0;
	i = -1;
	max = ft_sqrt(len * 4);
	r = 0;
	while(++i < len)
		temp[i] = tet[i];
	i = 0;
	while(i < len)
	{
		r = rec(tet,i,tab, max);
		if (r == 0)
		{
			i++;
		}
		if (r == 1)
		{
			tet[i] = temp[i];
			if (i == 0 )
			{
				max++;
				free(tab);
				tab = init_tab(max);
				i = 1;
			}
			i--;
		}
	}
	afficher(tab);
	return (0);
}

void affiche_tet(struct tetrim *tet ,int len)
{
	int j;
	j = 0;
	char **tab;
	tab = init_tab(ft_sqrt(len * 4));
	int i;
	int decal;
	decal = 0;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < 4)
		{
			printf ("lettre = %c x = %d y = %d \n",tet[i].lettre,tet[i].pos[j].x,tet[i].pos[j].y);
			j++;
		}
		i++;
		printf("\n");
	}
	i =	 add_titris(tet,len,tab);
}

void ft_solve(char **matrix)
{
	int        x;
	int        y;
	int			i_tet;
	int i2;
	int decal_y;
	struct tetrim  tet[26];
	int decal_x;
	int bl;
	int i_pos;
	char lettre;
	char **temp;
	x = 0;
	bl = 1;
	i_pos = 0;
	decal_x = 0;
	i_tet = 0;
	i2 = 0;
	decal_y = 0;
	lettre = 'A';
	temp = matrix;

	while (matrix[x])
	{
		y = 0;

		while (matrix[x][y])
		{
			if(matrix[x][y] == '#')
			{
				if (bl == 1)
				{
					decal_x = i2;
					decal_y = y;
				}
				tet[i_tet].lettre = lettre;
				tet[i_tet].pos[i_pos].x = i2 - decal_x;
				tet[i_tet].pos[i_pos].y = y - decal_y;
				bl = 0;
				i_pos++;
			}
			y++;
		}
		if (matrix[x][0] == '#' || matrix[x][0] == '.')
		{
			if (i2 == 3)
			{
				i2 = 0;
				bl= 1;
				i_tet++;
				i_pos = 0;
				lettre++;
			}
			else
				i2++;
		}
		x++;
	}
	affiche_tet(tet, i_tet);
}
