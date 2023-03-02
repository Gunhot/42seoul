/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:39:15 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/31 03:32:23 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(long n)
{
	int	c;

	if (n >= 10)
		print_num(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	calculate(int a, char *c, int b)
{
	long	result;

	if (c[0] == '+')
		result = a + b;
	if (c[0] == '-')
		result = a - b;
	if (c[0] == '*')
		result = a * b;
	if (c[0] == '/')
		result = a / b;
	if (c[0] == '%')
		result = a % b;
	if (result < 0)
	{
		write(1, "-", 1);
		result *= -1;
	}
	print_num(result);
	write(1, "\n", 1);
}
