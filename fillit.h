#ifndef FILLIT_H
# define FILLIT_H
#include "libft/includes/libft.h"

struct	list
{
	int	new_line;
	int	hash;
	int	dot;
	int square;
	int	n_line;
	int j;
	int relation;
	int	row;
}			var;

struct index
{
	int x;
	int y;
};

struct tetrim
{
	char lettre;
	struct index pos[4];
};

int		check_block(int fd);
void    ft_solve(char **tmp);

#endif
