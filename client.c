/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:25:29 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/22 09:07:53 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_msg(int pid, char msg)
{
	int	bit;
	
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
	
	i = 0;
	if (checkinput(argc, argv) == 1)
	{
		pid = ft_atoi(argv[1]);
		msg = ft_strdup(argv[2]);
		while (msg[i] != '\0')
		{
			send_msg(pid, msg[i]);
			i++;
		}	
	}
}