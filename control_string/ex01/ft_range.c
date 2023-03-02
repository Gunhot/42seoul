/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:30:46 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/25 16:43:57 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*result;
	int	i;

	if (min >= max)
		return (0);
	size = max - min;
	result = (int *)malloc(sizeof(int) * size);
	if (!result)
		return (0);
	i = 0;
	while (min < max)
		result[i++] = min++;
	return (result);
}
