/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:12:30 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/18 20:41:28 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_to_hex(unsigned char c)
{
	if (c > 9)
	{
		c -= 10;
		c += 'a';
	}
	else
		c += '0';
	write(1, &c, 1);
}

void	print_string(unsigned char *addr, int sizei)
{
	int		i;
	char	dot;

	dot = '.';
	i = 0;
	while (i < 16 && i < sizei)
	{
		if (32 <= *(addr + i) && *(addr + i) <= 126)
			write(1, addr + i, 1);
		else
			write(1, &dot, 1);
		i++;
	}
}

void	print_hex(unsigned char *addr, int sizei)
{
	int		i;
	char	c;

	c = ' ';
	i = 0;
	while (i < 16 && i < sizei)
	{
		print_to_hex(*(addr + i) / 16);
		print_to_hex(*(addr + i) % 16);
		if (i % 2)
			write(1, &c, 1);
		i++;
	}
	while (i < 16)
	{
		write(1, &c, 1);
		write(1, &c, 1);
		if (i % 2)
			write(1, &c, 1);
		i++;
	}
}

void	print_addr(unsigned long long addr, int i)
{
	char	c[2];

	if (i < 15)
		print_addr(addr / 16, ++i);
	print_to_hex(addr % 16);
	c[0] = ':';
	c[1] = ' ';
	if (i == 1)
		write(1, c, 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	char				new_l;

	new_l = '\n';
	i = 0;
	while (i < size)
	{
		print_addr((unsigned long long)(addr + i), 0);
		print_hex((addr + i), size - i);
		print_string((addr + i), size - i);
		i += 16;
		write(1, &new_l, 1);
	}
	return (0);
}
