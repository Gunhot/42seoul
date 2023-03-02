/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:12:30 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/25 17:00:42 by kun-lee          ###   ########.fr       */
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
#include <stdio.h>
int main(void)
{
		printf("< ex12 >\n");
	char	c12[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n a";

	printf("----------answer----------\n");
	printf("%s\n", "00007ffee16ab3e0: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin\n00007ffee16ab3f0: 6368 6573 090a 0963 2020 6573 7420 666f ches...c  est fo\n00007ffee16ab400: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on \n00007ffee16ab410: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.\n00007ffee16ab420: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..\n00007ffee16ab430: 0a09 6c6f 6c2e 6c6f 6c0a 2000           ..lol.lol. .a");
	printf("-------------------------\n");
	ft_print_memory((void *)c12, sizeof(c12));
	printf("----------output----------\n");
	return 0;
}
