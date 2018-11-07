/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 02:57:39 by bel-bouz          #+#    #+#             */
/*   Updated: 2018/11/07 21:22:37 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# include "libft/includes/libft.h"

typedef struct		s_var
{
	int	new_line;
	int	hash;
	int	dot;
	int	square;
	int	n_line;
	int	j;
	int	relation;
	int	row;
}					t_var;

typedef	struct		s_variable
{
	int			x;
	int			y;
	int			i_tet;
	int			i2;
	int			decal_y;
	int			decal_x;
	int			bl;
	int			i_pos;
	char		lettre;
}					t_variable;

typedef struct		s_index
{
	int x;
	int y;
}					t_index;

struct				s_tetrim
{
	char				lettre;
	struct s_index		pos[4];
}					tetrim;

int					check_block(int fd);
int					check_block1(char **tmp);
void				ft_solve(char **tmp);
int					moin_y(struct s_tetrim tet);
struct s_tetrim		decaly(struct s_tetrim tet, int max);
struct s_tetrim		decalx(struct s_tetrim tet, int max);
char				**init_tab(int row);
int					ft_sqrt(int x);
void				affich_fin(char **tab);
void				adapter(struct s_tetrim *tet, int len);
void				affiche_tet(struct s_tetrim *tet, int len);
void				vide_lettre(char **tab, char lettre, int max);
int					add_titris(struct s_tetrim *tet, int len,
					char **tab, int max);
void				fun1(struct s_tetrim *tet, int p,
		int max, struct s_tetrim temp);
int					fun2(struct s_tetrim *tet, int p, struct s_tetrim temp);

#endif
