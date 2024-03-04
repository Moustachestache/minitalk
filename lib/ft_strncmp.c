/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:31:45 by mjochum           #+#    #+#             */
/*   Updated: 2023/03/14 13:40:50 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char str1[50] = "un deux trois auqt";
	char str2[50] = "un deux trois aaaa";
	str2[1] = -4;
	printf("%d\n", ft_strncmp(str1, str2, 6));
	printf("%d", strncmp(str1, str2, 6));
}*/
