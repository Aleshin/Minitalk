/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <saleshin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:06:56 by saleshin          #+#    #+#             */
/*   Updated: 2024/02/19 19:07:04 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>

int	check_number(char c, int n)
{
	if (c < '0' || c > '9')
		return (1);
	if ((INT_MAX - n * 10) < c - '0')
		return (1);
	return (0);
}

int	ft_atoi(const char *str, pid_t *pid)
{
	int	i;
	int	digits;

	i = 0;
	if (!str[0] || (str[0] == '-'))
		return (1);
	digits = 0;
	while (str[i] != '\0')
	{
		if (check_number(str[i], digits))
			return (1);
		digits = digits * 10 + str[i] - '0';
		i++;
	}
	*pid = digits;
	return (0);
}

int	send_byte(char str, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (str & (1 << i))
		{
			if (kill(pid, SIGUSR2) == -1)
				return (1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				return (1);
		}
		usleep(100);
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3 || ft_atoi(argv[1], &pid))
		return (0);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_byte(argv[2][i], pid);
		i++;
	}
    printf("%s\n", argv[2]);
	return (0);
}
