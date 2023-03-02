/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:17:56 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/22 15:19:11 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_from_top(int map[4][4], int input, int col)
{
	int	row_idx;
	int	count;
	int	max_height;

	row_idx = 1;
	count = 1;
	max_height = map[0][col];
	while (row_idx <= 3)
	{
		if (map[row_idx][col] > max_height)
		{
			max_height = map[row_idx][col];
			count++;
		}
		row_idx++;
	}
	if (count == input)
		return (1);
	return (0);
}

int	check_col_from_bottom(int map[4][4], int input, int col)
{
	int	row_idx;
	int	count;
	int	max_height;

	row_idx = 2;
	count = 1;
	max_height = map[3][col];
	while (row_idx >= 0)
	{
		if (map[row_idx][col] > max_height)
		{
			max_height = map[row_idx][col];
			count++;
		}
		row_idx--;
	}
	if (count == input)
		return (1);
	return (0);
}

int	check_row_from_left(int map[4][4], int input, int row)
{
	int	col_idx;
	int	count;
	int	max_height;

	col_idx = 1;
	count = 1;
	max_height = map[row][0];
	while (col_idx <= 3)
	{
		if (map[row][col_idx] > max_height)
		{
			max_height = map[row][col_idx];
			count++;
		}
		col_idx++;
	}
	if (count == input)
		return (1);
	return (0);
}

int	check_row_from_right(int map[4][4], int input, int row)
{
	int	col_idx;
	int	count;
	int	max_height;

	col_idx = 2;
	count = 1;
	max_height = map[row][3];
	while (col_idx >= 0)
	{
		if (map[row][col_idx] > max_height)
		{
			max_height = map[row][col_idx];
			count++;
		}
		col_idx--;
	}
	if (count == input)
		return (1);
	return (0);
}

int	answer_check(int map[4][4], int *input)
{
	int	idx;

	idx = 0;
	while (idx < 4)
	{
		if (check_col_from_top(map, input[idx], idx)
			&& check_col_from_bottom(map, input[idx + 4], idx)
			&& check_row_from_left(map, input[idx + 8], idx)
			&& check_row_from_right(map, input[idx + 12], idx))
			idx++;
		else
			return (0);
	}
	return (1);
}
