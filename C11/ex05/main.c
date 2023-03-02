/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:27:38 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/31 03:39:45 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	calculate(int a, char *c, int b);

int	my_atoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] != '\0' && '0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	int	count;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	count = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	result = my_atoi(str + i);
	if (count % 2)
		result = -result;
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	main(int argc, char **argv)
{
	void	(*f[1])(int, char *, int);

	if (argc != 4)
		return (0);
	if (!(!ft_strcmp(argv[2], "+") || !ft_strcmp(argv[2], "-")
			|| !ft_strcmp(argv[2], "*") || !ft_strcmp(argv[2], "/")
			|| !ft_strcmp(argv[2], "%")))
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (!ft_strcmp(argv[2], "/") && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (!ft_strcmp(argv[2], "%") && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	f[0] = calculate;
	f[0](ft_atoi(argv[1]), argv[2], ft_atoi(argv[3]));
	return (0);
}
