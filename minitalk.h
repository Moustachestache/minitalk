/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:07:06 by mjochum           #+#    #+#             */
/*   Updated: 2023/06/09 18:28:16 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include "printf/ft_printf.h"
# include "lib/libft.h"

typedef struct s_message {
	int					i;
	int					size;
	int					received;
	unsigned char		*msgdecoded;
	unsigned long int	currentbit;
}			t_message;

#endif
