/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:44:59 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/18 22:21:31 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	exception(int nb)
{
	char	exc[11];

	if (nb == 0)
	{
		exc[0] = '0';
		write(1, &exc[0], 1);
	}
	else
	{
		exc[0] = '-';
		exc[1] = '2';
		exc[2] = '1';
		exc[3] = '4';
		exc[4] = '7';
		exc[5] = '4';
		exc[6] = '8';
		exc[7] = '3';
		exc[8] = '6';
		exc[9] = '4';
		exc[10] = '8';
		write(1, exc, 11);
	}
}

void	pos_num(int nb)
{
	int		n;
	char	c;

	if (nb >= 1)
	{
		n = nb % 10;
		nb /= 10;
		pos_num(nb);
		c = n + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	char	sign;

	sign = '-';
	if (nb == -2147483648 || nb == 0)
	{
		exception(nb);
	}
	else
	{
		if (nb < 0)
		{
			write (1, &sign, 1);
			nb = -nb;
		}
		pos_num(nb);
	}
}
