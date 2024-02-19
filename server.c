/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <saleshin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:04:49 by saleshin          #+#    #+#             */
/*   Updated: 2024/02/19 19:06:05 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	handle_sigusr(int sig)
{
	static int	byte;
	static int	counter;

	if (sig == SIGUSR1)
		byte = byte * 2;
	else
		byte = byte * 2 + 1;
	counter++;
	if (counter == 8)
	{
		write(1, &byte, 1);
		counter = 0;
		byte = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	pid = getpid();
	printf("%d\n", pid);
	while (1)
		pause();
	return (0);
}
