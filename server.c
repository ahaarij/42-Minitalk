/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:50:15 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/21 13:25:16 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	bits(int sig)
{
	static int	bit;
	static int	set;

	if (signal == SIGUSR1)
		set += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", set);
		bit = 0;
		set = 0;
	}

}

int	main(int argc, char **argv)
{
	int	pid;
	
	void(*argv);
	pid = getpid();
	if (argc != 1)
	{
		ft_printf("%s\n", "ur input is wrong loserrr -> ./server");
		return (0);
	}
	ft_printf("%s%d\n" "This is the Process ID ->", pid);
	signal(SIGUSR1, bits);
	signal(SIGUSR2, bits);
	while (1)
		pause();
	return (0);
}