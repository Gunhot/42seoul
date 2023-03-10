/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:02:13 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/21 23:57:04 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	i;
	long long	longn;

	if (nb == 1)
		return (1);
	longn = (long long)nb;
	i = 1;
	while (i * i <= longn)
	{
		if (longn == i * i)
			return (i);
		i++;
	}
	return (0);
}
