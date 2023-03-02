/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:30:46 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/25 17:49:10 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*ret;
	int	i;

	if (min >= max)
	{
		ret = NULL;
		*range = ret;
		return (0);
	}
	size = max - min;
	ret = (int *)malloc(sizeof(int) * size);
	if (!ret)
		return (0);
	i = 0;
	while (min < max)
		ret[i++] = min++;
	*range = ret;
	return (size);
}
