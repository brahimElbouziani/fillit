/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 00:34:03 by bel-bouz          #+#    #+#             */
/*   Updated: 2018/11/06 20:12:06 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:06:50 by mfilahi           #+#    #+#             */
/*   Updated: 2018/11/06 00:31:46 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


int    ft_sqrt(int x)
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
	i = 3;
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
	i = 3;
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
	int j;
	struct tetrim temp;

	i = 3;
	j = 0;
	temp = tet[p];

	while (i >= 0)
	{
		if (tet[p].pos[i].x > max - 1 || tet[p].pos[i].y > max - 1 )
		{
		//	printf("here \n");
			return (1);
		}
			//	printf("x =%d y = %d max = %d i = %d p = %d\n",tet[p].pos[i].x,tet[p].pos[i].y,max,i,p);
		if (tab[tet[p].pos[i].x][tet[p].pos[i].y] == '.')
		{
		//	if (tab[tet[p].pos[i].x][tet[p].pos[i].y] != '.')
			//	return (1);
			tab[tet[p].pos[i].x][tet[p].pos[i].y] = tet[p].lettre;
		//afficher(tab);
		//sleep(1);
		}
		else
		{
			vide_lettre(tab,tet[p].lettre,max);
			if (tet[p].pos[i].y < (max - 1))
			{
				tet[p] = decaly(tet[p], max);
			}
			else if (tet[p].pos[i].x < (max - 1))
			{
				tet[p]= decalx(tet[p], max);
				j = 0;
				while (j < 4)
				{
					tet[p].pos[j].y = temp.pos[j].y-1;
					j++;
				}
			}
			else if (tet[p].pos[i].x >=(max - 1) && tet[p].pos[i].y >= (max - 1))
			{
				j = 0;
				while (j < 4)
				{
					tet[p].pos[j].x = temp.pos[j].x;
					tet[p].pos[j].y = temp.pos[j].y;
					j++;
				}
				return (1);
			}
			i = 4;
			j = 0;
		}
		i--;
	}
	return (0);
}

int			add_titris(struct tetrim *tet,int len,char **tab,int max)
{
	int i;
	int r;
	struct tetrim temp[26];
	int j;
	j = 0;
	i = -1;

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
		//	tet[i] = temp[i];
		}
	}
	afficher(tab);
	return (0);
}

void affiche_tet(struct tetrim *tet ,int len)
{
	int j;
	int max;
	j = 0;
	char **tab;

	max = ft_sqrt(len * 4) + j;

	while (j < len)
	{
		if (tet[j].pos[3].x + 1 > max)
			max = tet[0].pos[3].x + 1;
		j++;
	}
	tab = init_tab(max);
	
	int i;
	int decal;
	decal = 0;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < 4)
		{
		//	printf ("lettre = %c x = %d y = %d  len = %d \n",tet[i].lettre,tet[i].pos[j].x,tet[i].pos[j].y,len);
			j++;
		}
		i++;
		printf("\n");
	}
	i =	 add_titris(tet,len,tab, max);
}

void  adapter(struct tetrim *tet , int len)
{
	int i;
	int j;
	int k;
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
			//	printf("decaly = %d",decal_y);
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
	adapter(tet,i_tet);
	affiche_tet(tet, i_tet);
}
