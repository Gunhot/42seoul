/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:10:16 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/14 23:51:17 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	start_num(int n)
{
	int	e_n;
	int	digit;
	int	num;

	e_n = n;
	digit = 1;
	num = 0;
	while (e_n-- > 0)
	{
		num += e_n * digit;
		digit *= 10;
	}
	return (num);
}

int	end_num(int n)
{
	int	num;
	int	e_n;
	int	digit;

	e_n = 9;
	digit = 1;
	num = 0;
	while (e_n >= 9 - n + 1)
	{
		num += e_n--*digit;
		digit *= 10;
	}
	return (num);
}

int	check_num(int num, int n)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (i < n - 1)
	{
		x = (num / 10) % 10;
		y = num % 10;
		if (x >= y)
			return (0);
		i++;
		num /= 10;
	}
	return (1);
}

void	print(int num, int n)
{
	char	str [10];
	int		i;
	int		digit;

	i = 0;
	digit = 1;
	while (i++ < n)
	{
		digit *= 10;
		str[i] = ' ';
	}
	digit /= 10;
	i = 0;
	while (i < n)
	{
		str[i] = (num / digit) % 10 + '0';
		digit /= 10;
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	cs[2];
	int		boundary[2];
	int		current_num;

	boundary[0] = start_num(n);
	boundary[1] = end_num(n);
	cs[0] = ',';
	cs[1] = ' ';
	current_num = boundary[0];
	while (current_num <= boundary[1])
	{
		if (check_num(current_num, n))
		{
			print(current_num, n);
			if (current_num < boundary[1])
			{
				write(1, &cs[0], 1);
				write(1, &cs[1], 1);
			}
		}
		current_num++;
	}
}
