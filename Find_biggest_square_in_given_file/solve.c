/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:04:46 by kun-lee           #+#    #+#             */
/*   Updated: 2023/02/01 09:27:21 by hwayu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_function.h"

int	**make_sizedmap(int size[])
{
	int	**sizemap;
	int	i;

	sizemap = (int **)malloc(sizeof(int *) * (size[0] + 1));
	if (!sizemap)
		return (0);
	i = 0;
	while (i <= size[0])
	{
		sizemap[i] = (int *)malloc(sizeof(int) * (size[1] + 1));
		sizemap[i][0] = 0;
		i++;
	}
	i = 0;
	while (i <= size[1])
	{
		sizemap[0][i] = 0;
		i++;
	}
	return (sizemap);
}

int	get_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

int	**calc_size(int **map, int *size)
{
	int	i;
	int	j;
	int	**sized_map;
	int	temp;

	sized_map = make_sizedmap(size);
	i = 0;
	while (i < size[0])
	{
		j = 0;
		while (j < size[1])
		{
			if (map[i][j] == 1)
				sized_map[i + 1][j + 1] = 0;
			else
			{
				temp = get_min(sized_map[i][j + 1], sized_map[i + 1][j],
						sized_map[i][j]);
				sized_map[i + 1][j + 1] = temp + 1;
			}
			j++;
		}
		i++;
	}
	return (sized_map);
}

t_size_coord	get_max_size(int **sized_map, int size[])
{
	t_size_coord	size_coord;
	int				x;
	int				y;

	size_coord.size = 0;
	size_coord.x = 0;
	size_coord.y = 0;
	y = 0;
	while (y < size[0])
	{
		x = 0;
		while (x < size[1])
		{
			if (sized_map[y + 1][x + 1] > size_coord.size)
			{
				size_coord.size = sized_map[y + 1][x + 1];
				size_coord.x = x;
				size_coord.y = y;
			}
			x++;
		}
		y++;
	}
	return (size_coord);
}
