/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaarij <ahaarij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:25:29 by ahaarij           #+#    #+#             */
/*   Updated: 2024/01/21 13:29:48 by ahaarij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	long			result;
	long			sign;
	unsigned int	i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	isstrdig(char *str)
{
	int	i;
	i = 0;
	while ()
}

char	*ft_strdup(const char *s1)
{
	unsigned int	j;
	unsigned int	i;
	char			*dest;

	i = 0;
	j = ft_strlen(s1);
	dest = (char *)malloc(sizeof(*dest) * (j + 1));
	if (!dest)
		return (NULL);
	while (i < j)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
// REMOVE STRDUP, PUT LIBFT!
int	checkinput(int argc, char **argv)
{
	int	correct_input;

	correct_input = 0;
	if (argc != 3)
		ft_printf("%s\n", "Please use the correct format! ./client <PID> <Message>");
	else if ()
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;
	char *msg;
	
	i = 0;
	pid = ft_atoi(argv[1]);
	msg = ft_strdup(argv[2]);
}