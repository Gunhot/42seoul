/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:26:40 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/26 23:48:14 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	my_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	my_print_num(long n)
{
	char	c;

	if (n >= 10)
		my_print_num(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		my_print_str(par[i].str);
		write(1, "\n", 1);
		my_print_num(par[i].size);
		write(1, "\n", 1);
		if (par[i].copy)
			my_print_str(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
