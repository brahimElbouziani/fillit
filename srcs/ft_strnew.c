/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 02:36:04 by mfilahi           #+#    #+#             */
/*   Updated: 2018/11/09 02:17:20 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

char		*ft_strcat(char *s1, const char *s2)
{
	int j;
	int i;

	j = 0;
	i = 0;
	j = (int)ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[j] = s2[i];
		j++;
		i++;
	}
	s1[j] = '\0';
	return (s1);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char			*strnew;
	size_t			size;
	int				i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	strnew = ft_strnew(size);
	if (!strnew)
		return (NULL);
	while (s1[i] != '\0')
	{
		strnew[i] = s1[i];
		i++;
	}
	strnew[i] = '\0';
	ft_strcat(strnew, s2);
	strnew[size + 1] = '\0';
	return (strnew);
}

void		*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*str;

	str = (char*)b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

void		ft_bzero(void *s, size_t n)
{
	char		*ptr;
	size_t		i;

	if (!n || n == 0)
		return ;
	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

char		*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(str, size + 1);
	return ((char *)str);
}
