/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:18:20 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/22 15:18:22 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	answer_check(int map[4][4], int *inputs);

int	check_zero_exist(int map[4][4], int *row_index, int *col_index)
{
	*row_index = 0;
	while (*row_index <= 3)
	{
		*col_index = 0;
		while (*col_index <= 3)
		{
			if (map[*row_index][*col_index] == 0)
				return (1);
			(*col_index)++;
		}
		(*row_index)++;
	}
	return (0);
}

int	col_redundancy(int map[4][4], int col, int height)
{
	int	row_index;

	row_index = 0;
	while (row_index <= 3)
	{
		if (map[row_index][col] == height)
			return (1);
		row_index++;
	}
	return (0);
}

int	row_redundancy(int map[4][4], int row, int height)
{
	int	col_index;

	col_index = 0;
	while (col_index <= 3)
	{
		if (map[row][col_index] == height)
			return (1);
		col_index++;
	}
	return (0);
}

int	check_redundancy(int map[4][4], int row, int col, int height)
{
	if ((row_redundancy(map, row, height) == 0)
		&& (col_redundancy(map, col, height) == 0))
		return (0);
	return (1);
}

int	solve(int map[4][4], int *input)
{
	int	box_height;
	int	row;
	int	col;

	if ((check_zero_exist(map, &row, &col) == 0)
		&& (answer_check(map, input) == 1))
		return (1);
	if (row == 4 && col == 4)
		return (0);
	box_height = 1;
	while (box_height <= 4)
	{
		if (check_redundancy(map, row, col, box_height) == 0)
		{
			map[row][col] = box_height;
			if (solve(map, input) == 1)
				return (1);
			map[row][col] = 0;
		}
		box_height++;
	}
	return (0);
}
