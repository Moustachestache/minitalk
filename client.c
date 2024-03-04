/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:07:03 by mjochum           #+#    #+#             */
/*   Updated: 2023/06/08 19:11:56 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive(int signo)
{
	(void)signo;
	usleep(50);
}

void	sendint(int pid, int size)
{
	unsigned long int		byte;

	byte = 1073741824;
	while (byte > 0)
	{
		if (size & byte)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		byte /= 2;
		pause();
	}
}

void	sendtext(int pid, char *str)
{
	int	i;
	int	byte;

	i = 0;
	while (str[i] && str[i] != '\0')
	{
		byte = 128;
		while (byte > 0)
		{
			if (str[i] & byte)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			byte /= 2;
			pause();
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	int						pid;
	int						i;
	int						size;

	signal(SIGUSR1, &receive);
	signal(SIGUSR2, &receive);
	if (ac != 3)
		return (ft_printf("Incorrect syntax. Use: %s [PID] [MESSAGE]\n", av[0]));
	pid = ft_atoi(av[1]);
	i = 0;
	size = ft_strlen(av[2]);
	if (kill(pid, SIGUSR2) != 0)
		return (ft_printf("PID incorrect.\n"));
	pause();
	sendint(pid, size);
	sendtext(pid, av[2]);
}
