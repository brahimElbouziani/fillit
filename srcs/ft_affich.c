/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affich.                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 14:40:06 by mfilahi           #+#    #+#             */
/*   Updated: 2018/11/09 17:11:55 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putendl(char const *s)
{
	while (*s)
		ft_putchar(*s++);
	write(1, "\n", 1);
}

void		affich_fin(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

int			check_block(int fd)
{
	char		*line;
	char		*tmp[2550];
	int			i;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmp[i] = ft_strdup(line);
		i++;
	}
	tmp[i] = NULL;
	if (i > 3 && check_block1(tmp))
		ft_solve(tmp);
	else
		ft_putendl("error");
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		check_block(fd);
	}
	else
	{
		ft_putstr("Usage : ");
		ft_putstr(argv[0]);
		ft_putendl(" tetris_list_file");
		exit(1);
	}
	return (0);
}
