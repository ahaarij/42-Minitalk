/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:50:15 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/28 13:49:08 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	bits(int sig) // reconstructs the character from bits
{
	static int	bit;
	static int	set;

	if (sig == SIGUSR1)			// if bit is 1
		set += 1 << (7 - bit);	// sets the bit to 1				100001
	bit++;
	if (bit == 8)				// once bits form a byte
	{
		ft_printf("%c", set);	// prints out the character formed
		bit = 0;
		set = 0;
	}
}

int	main(int argc, char **argv)
{
	int	serv_pid;
	
	(void)argv;
	serv_pid = getpid();
	if (argc != 1)
	{
		ft_printf("%s\n", "Incorrect input!\nUse: ./server");
		return (0);
	}
	ft_printf("%s%d\n", "This is the Process ID:", serv_pid);
	signal(SIGUSR1, bits);												// this is a signal handler, when it recieves SIGUSR1 signal, it will execute the function bits with SIGUSR1 as an argument
	signal(SIGUSR2, bits);												// this is a signal handler, when it recieves SIGUSR2 signal, it will execute the function bits with SIGUSR2 as an argument
	while (1)
		pause();
	return (0);
}