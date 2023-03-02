/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:18:08 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/22 16:47:31 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	start(int *inputs);

int	delete_space(char *argv, char *input_str)
{
	int	argv_idx;
	int	str_idx;

	argv_idx = 0;
	str_idx = 0;
	while (argv[argv_idx] != '\0')
	{	
		if (str_idx == 16)
			return (0);
		if (argv_idx % 2 && argv[argv_idx] != ' '
			|| argv_idx % 2 == 0 && argv[argv_idx] == ' ')
			return (0);
		if (argv_idx % 2 && argv[argv_idx] == ' ')
			argv_idx++;
		input_str[str_idx] = argv[argv_idx];
		str_idx++;
		argv_idx++;
	}
	input_str[str_idx] = '\0';
	return (1);
}

int	input_check(char *input_str, int *input_int)
{
	int	idx;

	idx = 0;
	while (input_str[idx] != '\0')
	{
		if ('1' <= input_str[idx] && input_str[idx] <= '4')
			input_int[idx] = input_str[idx] - '0';
		else
			return (0);
		idx++;
	}
	if (idx != 16)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	input_str[17];
	int		input_int[16];

	if (argc == 2)
	{
		if ((delete_space(argv[1], input_str) == 1)
			&& (input_check(input_str, input_int) == 1))
			start(input_int);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
