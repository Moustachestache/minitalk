/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:02:34 by mjochum           #+#    #+#             */
/*   Updated: 2023/04/14 18:02:15 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*r;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	r = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!r)
		return (NULL);
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	return (r);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*r;
	size_t	i;
	size_t	tmp;

	tmp = nmemb * size;
	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	else if (tmp / size != nmemb)
		return (0);
	r = (char *)malloc(nmemb * size);
	if (!r)
		return (NULL);
	while (i < nmemb * size)
	{
		r[i] = '\0';
		i++;
	}
	return ((void *)r);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_hasret(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			return (i);
	return (-1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*o;

	o = s;
	i = 0;
	while (i < n)
	{
		o[i] = '\0';
		i++;
	}
}
