/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:25:29 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/23 20:41:11 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	send_msg(int pid, char msg)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if(msg >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
		bit--;
	}
}

static int	isstrdig(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			result = 1;
		else
			return (0);
		i++;
	}
	return (result);
}

int	checkinput(int argc, char **argv)
{
	int	correct_input;

	correct_input = 0;
	if (argc != 3)
		ft_printf("%s\n", "Please use the correct format! ./client <PID> <Message>");
	else if (!isstrdig(argv[1]))
		ft_printf("%s\n", "Wrong Format!, PID should only contain numbers!");
	else if (argv[2] == 0)
		ft_printf("%s\n", "Please input a non-empty message!");
	else
		correct_input = 1;
	return (correct_input);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;
	char *msg;
	
	if (checkinput(argc, argv) == 1)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		msg = ft_strdup(argv[2]);
		while (msg[i] != '\0')
		{
			send_msg(pid, msg[i]);
			i++;
		}
		free (msg);
		send_msg(pid, '\n');
	}
	return (0);
}