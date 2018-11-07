/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 14:36:56 by mfilahi           #+#    #+#             */
/*   Updated: 2018/11/07 23:05:16 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		check_block2(char **tmp, int *dot, int *hash)
{
	char		*p;
	int			i;

	p = *tmp;
	i = 0;
	while (p[i])
	{
		if (p[i] == '.')
			(*dot)++;
		else
			(*hash)++;
		i++;
	}
	if (i != 4)
	{
		ft_putendl("error");
		exit(0);
	}
}

void		check_block3(int *dot, int *hash, int *n_line, int *square)
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
		{
			ft_putendl("error");
			exit(0);
		}
	}
}

void		inisial(struct s_var *var)
{
	var->new_line = 0;
	var->dot = 0;
	var->hash = 0;
	var->square = 0;
	var->n_line = 0;
	var->row = 0;
	var->relation = 0;
}

void		fonction(char **tmp, struct s_var *var)
{
	while (tmp[var->row][var->j] && var->j < 4)
	{
		if (tmp[var->row][var->j] == '#')
		{
			if (var->j < 3)
				if (tmp[var->row][var->j] == tmp[var->row][var->j + 1])
					var->relation++;
			if (var->n_line < 3)
				if (tmp[var->row][var->j] == tmp[var->row + 1][var->j])
					var->relation++;
		}
		var->j++;
	}
	if (*tmp[var->row] == '.' || *tmp[var->row] == '#')
	{
		check_block2(&tmp[var->row], &var->dot, &var->hash);
		var->n_line++;
	}
}

int			check_block1(char **tmp)
{
	struct s_var var;

	inisial(&var);
	while (tmp[var.row])
	{
		var.j = 0;
		if (*tmp[var.row] == '\0')
		{
			if (var.dot > 0 || var.hash > 0
					|| var.n_line > 0 || var.relation < 3)
				return (0);
			var.new_line++;
			var.relation = 0;
		}
		fonction(tmp, &var);
		check_block3(&var.dot, &var.hash, &var.n_line, &var.square);
		var.row++;
	}
	if (var.n_line == 0 && var.new_line == var.square - 1 && var.relation >= 3)
		return (1);
	return (0);
}
