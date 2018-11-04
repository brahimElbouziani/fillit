/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:06:50 by mfilahi           #+#    #+#             */
/*   Updated: 2018/11/04 21:33:48 by bel-bouz         ###   ########.fr       */
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
int		rec(struct tetrim tet, char **tab, int max)
{
	int i;
	int j;
	struct tetrim temp;

		i = 3;
		j = 0;
		temp = tet;

		while (i >= 0)
		{
			if (max == 5)
			{
				printf("\n %d \n",i);
				afficher(tab);
			}
			//printf("hehe = %d",tet.pos[i].y);
			if (ft_isalpha(tab[tet.pos[i].x][tet.pos[i].y]) == 0)
			{
							tab[tet.pos[i].x][tet.pos[i].y] = tet.lettre;
				afficher(tab);
				sleep(1);
			}
			else
			{
				vide_lettre(tab,tet.lettre,max);
				
				if (tet.pos[i].y != (max - 1))
				{
					tet = decaly(tet, max);
				}
				else if (tet.pos[i].x != (max - 1))
				{
					tet = decalx(tet, max);
					while (j < 4)
					{
						tet.pos[j].y = temp.pos[j].y;
						j++;
					}
				}
				if (tet.pos[i].x == (max - 1))
				{
					j = 0;
					while (j < 4)
					{
						tet.pos[j].x = temp.pos[j].x;
						tet.pos[j].y = temp.pos[j].y;
						j++;
					}

					return (0);
				}
				i = 4;
				j = 0;
			}
				i--;
		}
		return (1);
}


int			add_titris(struct tetrim *tet,int len,char **tab)
{
	int i;
	int max;
	i = 0;
	max = ft_sqrt(len * 4);

	while(i < len)
	{
	//	rec(tet[i], tab, max); 
		if (rec(tet[i], tab, max) == 0)
		{
			max++;
			tab = init_tab(max);
			//printf(" -- >%d ",ft_sqrt(len*4) + 1);
			i = -1;
		}
		i++;
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


/*
int mini_y(char **matrix,int i)
{
	int j;
	int y;

	j = 0;
	y = 3;
	while (i < i + 4)
		{
			j = 0;
			while (j < 4)
			{
				if (matrix[i][j] == '#' && y > j)
					y = j;
				j++;
			}
			i++;
		}
	return (y);
}*/

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
			//	printf("x = %d . y = %d \n",decal_x,decal_y);
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
