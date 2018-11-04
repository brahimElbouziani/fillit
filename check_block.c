/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 14:36:56 by mfilahi           #+#    #+#             */
/*   Updated: 2018/11/02 20:46:21 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"
#include <stdio.h>

void	check_block2(char **tmp, int *dot, int *hash)
{
	char	*p;
	int		i;

	p = *tmp;
	i = 0;
	while (p[i] == '.' || p[i] == '#')
	{
		if (p[i] == '.')
			(*dot)++;
		else
			(*hash)++;
		i++;
	}
	if (i != 4)
		exit (0);
}

void	check_block3(int *dot, int *hash, int *n_line, int *square)
{
	if ((*dot == 12 && *hash == 4))
	{
		if (*n_line == 4)
		{
			*dot = 0;
			*hash = 0;
			*n_line = 0;
			(*square)++;
		}
		else
			exit (0);
	}	
}

int		check_block1(char **tmp)
{
	var.new_line = 0;
	var.dot = 0;
	var.hash = 0;
	var.square = 0;
	var.n_line = 0;
	var.row = 0;
	var.relation = 0;
	while (tmp[var.row])
	{
		var.j = 0;
		if (*tmp[var.row] == '\0')
		{
			if (var.dot > 0 || var.hash > 0 || var.n_line > 0 || var.relation < 3)
				return (0);
			var.new_line++;
			var.relation = 0;
		}
		while (tmp[var.row][var.j] && var.j < 4)
		{
			if (tmp[var.row][var.j] == '#')
			{
				if (var.j < 3)
					if (tmp[var.row][var.j] == tmp[var.row][var.j+1])
						var.relation++;
				if (var.n_line < 3)
					if (tmp[var.row][var.j] == tmp[var.row+1][var.j])
						var.relation++;
			}
		//	printf("  tmp[%d][%d] = %c",var.n_line,var.j,tmp[var.row][var.j]);
			var.j++;
		}
		printf("\n");
		if (*tmp[var.row] == '.' || *tmp[var.row] == '#')
		{
			check_block2(&tmp[var.row], &var.dot, &var.hash);
			var.n_line++;
		}
		check_block3(&var.dot, &var.hash, &var.n_line, &var.square);
		var.row++;
	}
	if (var.new_line == var.square - 1 && var.relation >= 3)
		return (1);
	return (0);
}

int		check_block(int fd)
{
	char	*line;
	char	*tmp[255];
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmp[i] = ft_strdup(line);
		printf("%s\n",tmp[i]);
		i++;
	}
	tmp[i] = NULL;
	if (check_block1(tmp))
		ft_solve(tmp);
		return (0);
}
