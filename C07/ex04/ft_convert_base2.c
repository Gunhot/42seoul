/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:41:58 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/25 14:29:22 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_len(long nbr, int bn)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		i++;
		nbr /= (long)bn;
	}
	return (i);
}

char	*int_to_string(long stopover, char *base, int bn)
{
	char	*result;
	int		r_len;
	int		i;
	int		j;

	r_len = find_len(stopover, bn);
	result = (char *)malloc(sizeof(char) * r_len + 1);
	i = 0;
	if (stopover < 0)
	{
		stopover = -stopover;
		result[0] = '-';
		i++;
	}
	j = r_len - 1;
	while (j >= i)
	{
		result[j] = base[stopover % bn];
		stopover /= bn;
		j--;
	}
	result[r_len] = '\0';
	return (result);
}
