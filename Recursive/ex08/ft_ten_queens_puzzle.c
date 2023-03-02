/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:38:26 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/22 19:24:57 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int *str)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = str[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	check(int *str, int index, int i)
{
	int	j;

	j = 0;
	while (j < index)
	{
		if (str[j] == i)
			return (0);
		if ((index - j == i - str[j])
			|| (j - index == i - str[j]))
			return (0);
		j++;
	}
	return (1);
}

void	searching(int *str, int index, int *count)
{
	int	i;

	i = 0;
	if (index == 10)
	{
		print(str);
		(*count)++;
	}
	while (i <= 9)
	{
		if (check(str, index, i) == 1)
		{
			str[index] = i;
			searching(str, index + 1, count);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	str[10];
	int	i;
	int	count;

	i = 0;
	while (i < 10)
	{
		str[i] = 0;
		i++;
	}
	count = 0;
	searching(str, 0, &count);
	return (count);
}
