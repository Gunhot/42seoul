/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:33:05 by kun-lee           #+#    #+#             */
/*   Updated: 2023/02/01 09:49:18 by hwayu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_function.h"

void	free_double_char(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_double_int(int **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(int **map, int **sized_map, int n)
{
	free_double_int(map, n);
	free_double_int(sized_map, n + 1);
}
