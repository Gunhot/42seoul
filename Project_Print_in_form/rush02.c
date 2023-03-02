/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:23:32 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/14 17:31:21 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	rush(int x, int y);
void	side(int x, int y, int x_pos, int y_pos);
void	mid(int y, int y_pos);
void	ft_putchar(char c);
void	rush(int x, int y)
{
	int	y_pos;
	int	x_pos;
	y_pos = 1;
	while (y_pos <= y)
	{
		x_pos = 1;
		while (x_pos <= x)
		{
			if (x_pos == 1 || x_pos == x)
			{
				side (x, y, x_pos, y_pos);
			}
			else
			{
				mid(y, y_pos);
			}
			x_pos++;
		}
		ft_putchar('\n');
		y_pos++;
	}
}
void	side(int x, int y, int x_pos, int y_pos)
{
	if ((x_pos == 1 && y_pos == 1) || (x_pos == x && y_pos == 1))
	{
		ft_putchar('A');
	}
	else if ((x_pos == 1 && y_pos == y) || (x_pos == x && y_pos == y))
	{
		ft_putchar('C');
	}
	else
	{
		ft_putchar('B');
	}
}
void	mid(int y, int y_pos)
{
	if (y_pos == 1 || y_pos == y)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}
