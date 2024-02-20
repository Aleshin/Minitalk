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
#include <signal.h>

int	print_pid(pid_t num)
{
	char	symbol;

	if (num / 10 != 0)
		print_pid(num / 10);
	symbol = (char)(num % 10) + '0';
	write (1, &symbol, 1);
	return (0);
}

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
		if (byte == '\0')
			write(1, "\n", 1);
		else
			write(1, &byte, 1);
		counter = 0;
		byte = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handle_sigusr);
	signal(SIGUSR2, handle_sigusr);
	print_pid(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
