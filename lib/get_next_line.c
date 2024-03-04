/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:06:25 by mjochum           #+#    #+#             */
/*   Updated: 2023/04/18 21:39:15 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_info	info[1024];
	char			*str;

	if (fd < 0 || read(fd, info[fd].leftovers, 0) < 0)
		return (NULL);
	if (!info[fd].readsize || !info[fd].leftovers)
	{
		info[fd].leftovers = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!info[fd].leftovers)
			return (NULL);
		info[fd].readsize = read(fd, info[fd].leftovers, BUFFER_SIZE);
	}
	str = ft_strdup(info[fd].leftovers);
	while (info[fd].readsize > 0
		&& ft_hasret(info[fd].leftovers) < 0 && ft_hasret(str) < 0)
	{
		ft_bzero(info[fd].leftovers, BUFFER_SIZE);
		info[fd].readsize = read(fd, info[fd].leftovers, BUFFER_SIZE);
		str = ft_stradd(str, info[fd]);
	}
	str = ft_trimshit(str, info[fd]);
	return (str);
}

void	*ft_stradd(char *str, t_info info)
{
	char	*swap;
	int		i;
	int		j;
	int		s;

	s = ft_strlen(str) + ft_strlen(info.leftovers);
	i = 0;
	j = 0;
	swap = ft_calloc(s + 1, sizeof(char));
	if (!swap)
		return (NULL);
	while (str[i])
	{
		swap[i] = str[i];
		i++;
	}
	while (info.leftovers[j])
	{
		swap[i + j] = info.leftovers[j];
		j++;
	}
	free (str);
	return (swap);
}

void	*ft_trimshit(char *str, t_info info)
{
	char	*swap;
	int		index;
	int		i;

	if (ft_strlen(str) == 0 || info.readsize < 0)
		return (ft_panic(str, info, 69));
	if (ft_hasret(str) < 0)
		return (ft_panic(str, info, 420));
	i = -1;
	index = ft_hasret(str);
	swap = ft_calloc(index + 1, sizeof(char));
	while (++i < index)
		swap[i] = str[i];
	i = -1;
	ft_bzero(info.leftovers, BUFFER_SIZE);
	while (++i < BUFFER_SIZE && str[index + i])
		info.leftovers[i] = str[index + i];
	free(str);
	return (swap);
}

// don't panic!
char	*ft_panic(char *str, t_info info, int panic_type)
{
	if (panic_type == 69)
	{
		free(info.leftovers);
		free(str);
		return (NULL);
	}
	else if (panic_type == 420)
	{
		free(info.leftovers);
		return (str);
	}
	return (NULL);
}
