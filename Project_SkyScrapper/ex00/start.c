/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:18:29 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/22 15:18:31 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	solve(int map[4][4], int *input);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_map(int map[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row <= 3)
	{
		col = 0;
		while (col <= 3)
		{
			ft_putchar(map[row][col] + '0');
			if (col < 3)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

void	start(int *input)
{
	int	row_index;
	int	col_index;
	int	map[4][4];

	row_index = 0;
	while (row_index <= 3)
	{
		col_index = 0;
		while (col_index <= 3)
		{
			map[row_index][col_index] = 0;
			col_index++;
		}
		row_index++;
	}
	if (solve(map, input) == 1)
		print_map(map);
	else
		write(1, "Error\n", 6);
}
