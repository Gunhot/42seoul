/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:41:58 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/19 23:25:54 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	print_in_base(unsigned int nbr, char *base, unsigned int bn)
{
	if (nbr >= bn)
	{
		print_in_base(nbr / bn, base, bn);
	}
	write(1, &base[nbr % bn], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	bn;

	bn = base_check(base);
	if (!bn)
		return ;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	print_in_base(nbr, base, bn);
}
