/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-bouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 00:42:58 by bel-bouz          #+#    #+#             */
/*   Updated: 2018/11/10 15:22:05 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define BUFF_SIZE 1

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

typedef struct		s_tetrim
{
	char		lettre;
	t_index		pos[4];
}					t_tetrim;

void				check_block2(char **tmp, int *dot, int *hash);
void				check_block3(int *dot, int *hash, int *n_line, int *square);
void				inisial(t_var *var);
void				ft_function(char **tmp, t_var *var);
void				ft_strdel(char **as);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strchr(const char *s, int c);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				inisial_solvevar(t_variable *solve);
void				ft_retour(char **matrix, t_variable *solve);
int					cat_line(int fd, char **line, char **str);
int					check_block(int fd);
int					check_block1(char **tmp);
void				ft_solve(char **tmp);
void				moin_y(t_tetrim tet, int *min);
void				decaly(t_tetrim *tet, int p, int max);
char				**init_tab(int row);
int					ft_sqrt(int x);
void				affich_fin(char **tab);
void				adapter(t_tetrim *tet, int len);
void				affiche_tet(t_tetrim *tet, int len);
void				vide_lettre(char **tab, char lettre, int max);
int					add_titris(t_tetrim *tet, int len,
					char **tab, int max);
void				fun1(t_tetrim *tet, int p,
		int max, t_tetrim temp);
int					fun2(t_tetrim *tet, int p,
		t_tetrim temp);
char				*ft_strdup(const char *s1);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
char				*ft_strnew(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
int					get_next_line(const int fd, char **line);
void				ft_putstr(char const *s);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					rec(t_tetrim *tet, int p, char **tab, int max);
int					add_titris(t_tetrim *tet, int len, char **tab, int max);

#endif
