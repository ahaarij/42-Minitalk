/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:25:29 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/28 13:53:53 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	send_msg(int pid, char msg)	//deconstructs characters into bits and sends it using kill
{
	int	bit;

	bit = 7;					// starts with most significant bit which is the first bit (leftmost)
	while (bit >= 0)
	{
		if(msg >> bit & 1)		// checks if the current bit is 1 ( & 1 is the same as == 1 ) after shifting to the right 'bit' amount of times.
			kill(pid, SIGUSR1);	// kill takes in a process ID and signal. it send the specified signal to the specified process id. in this case it will send to server.
		else
			kill(pid, SIGUSR2);
		usleep(400);			// 0.8ms before processing next bit. controls rate of signal transmission.
		bit--;					// keeps doing this until bit reaches 0 aka character completed
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
	if (argv[2] == 0)
		ft_printf("%s\n", "Please input a non-empty message!");
	else if (argc != 3)
		ft_printf("%s\n", "Please use the correct format! ./client <PID> <Message>");
	else if (!isstrdig(argv[1]))
		ft_printf("%s\n", "Wrong Format!, PID should only contain numbers!");
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

// note to keep in mind
// ascii is converted to binary like this
// lets say we're converting B to binary
// ascii for B is 66
// so we start dividing by 2. if there is a remainder, it is set to 1. and if there isnt a remainder, it is set to 0 as such:
// 66 / 2 = 33 (0) (Least significant bit, so this will be on the right side)
// 33 / 2 = 16.5 (1)
// 16 / 2 = 8 (0)
// 8 / 2 = 4 (0)
// 4 / 2 = 2 (0)
// 2 / 2 = 1 (0)
// 1 / 2 = 0.5 (1) (Most significant bit, so this will be on the left side)
// the way we put this into binary is:
// Most significant on the left and everything in between until Least significant bit is on the right
// so the binary conversion would be
// 1000010