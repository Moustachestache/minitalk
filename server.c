/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:10:42 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/28 13:54:40 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message	*setmsg(void)
{
	t_message	*msg;

	msg = ft_calloc(1, sizeof(t_message));
	msg->currentbit = 2147483648;
	msg->i = -1;
	msg->msgdecoded = NULL;
	return (msg);
}

t_message	*endmessage(t_message *msg)
{
	ft_printf("%s\n", msg->msgdecoded);
	free(msg->msgdecoded);
	free(msg);
	return (NULL);
}

void	handler(int signo, siginfo_t *info, void *context)
{
	static t_message	*msg;

	(void)context;
	if (msg == NULL || !msg)
		msg = setmsg();
	if (msg->received && msg->received < 32 && signo == SIGUSR1)
		msg->size += msg->currentbit;
	else if (msg->received > 31)
	{
		if (msg->msgdecoded == NULL)
			msg->msgdecoded = ft_calloc(msg->size + 1, sizeof(char));
		if (msg->currentbit == 0)
		{
			msg->currentbit = 128;
			msg->i++;
		}
		if (signo == SIGUSR1)
			msg->msgdecoded[msg->i] += msg->currentbit;
	}
	msg->received++;
	msg->currentbit /= 2;
	if ((msg->i + 1) == msg->size && msg->currentbit == 0)
		msg = endmessage(msg);
	kill(info->si_pid, signo);
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("PID: %i\n", getpid());
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
