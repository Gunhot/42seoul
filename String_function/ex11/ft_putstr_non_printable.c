/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:14:36 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/18 20:41:19 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable2(char c)
{
	if (!(32 <= c && c <= 126))
		return (0);
	return (1);
}

void	chnum_to_sixteen(unsigned char ch)
{
	unsigned char	c[2];
	char			slash;
	int				i;

	slash = '\\';
	write (1, &slash, 1);
	c[0] = ch / 16;
	c[1] = ch % 16;
	i = 0;
	while (i < 2)
	{
		if (c[i] > 9)
		{
			c[i] -= 10;
			c[i] += 'a';
		}
		else
		{
			c[i] += '0';
		}
		i++;
	}
	write(1, c, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_str_is_printable2(str[i]))
			chnum_to_sixteen(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
