/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 00:47:15 by kun-lee           #+#    #+#             */
/*   Updated: 2023/02/01 09:55:47 by hwayu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_function.h"

void	print_map(int **map, char *c, int *size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size[0])
	{
		x = 0;
		while (x < size[1])
		{
			write(1, &c[map[y][x]], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	draw(int **map, int **sized_map, char *c, int *size)
{
	t_size_coord	size_coord;
	int				x;
	int				y;

	size_coord = get_max_size(sized_map, size);
	y = 0;
	while (y < size_coord.size)
	{
		x = 0;
		while (x < size_coord.size)
		{
			map[size_coord.y - y][size_coord.x - x] = 2;
			x++;
		}
		y++;
	}
	print_map(map, c, size);
}

int	main(int argc, char **argv)
{
	int		i;
	int		**map;
	int		**sized_map;
	char	c[3];
	int		size[2];

	i = 1;
	if (argc == 1)
		exception(c, size);
	while (i < argc)
	{
		map = make_map(argv[i], c, size);
		if (map)
		{
			sized_map = calc_size(map, size);
			draw(map, sized_map, c, size);
			free_all(map, sized_map, size[0]);
		}
		else
			write(1, "map error\n", 10);
		i++;
	}
	return (0);
}
