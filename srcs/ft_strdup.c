/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfilahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:27:44 by mfilahi           #+#    #+#             */
/*   Updated: 2018/11/09 17:15:25 by bel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ptr;
	char		*ptr2;
	char		temp;

	ptr = dst;
	ptr2 = (char *)src;
	i = 0;
	while (i < n)
	{
		temp = ptr2[i];
		ptr[i] = temp;
		i++;
	}
	return (dst);
}

void		ft_putstr(char const *s)
{
	while (*s)
		ft_putchar(*s++);
}

size_t		ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (s[len] && ++len)
		;
	return (len);
}

char		*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while ((dst[i] = src[i]))
		i++;
	return (dst);
}

char		*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		s1_len;

	s1_len = ft_strlen(s1);
	if (!(s2 = (char *)malloc(sizeof(char) * s1_len + 1)))
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}
