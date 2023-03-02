/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:03:09 by kun-lee           #+#    #+#             */
/*   Updated: 2023/02/01 16:39:45 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_function.h"

int	c_redun(char *c)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!(32 <= c[i] && c[i] <= 126))
			return (0);
		i++;
	}
	if (c[0] == c[1])
		return (0);
	if (c[0] == c[2])
		return (0);
	if (c[1] == c[2])
		return (0);
	return (1);
}

int	first_line(char *str, char *c)
{
	int	result;
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i--])
		return (0);
	j = 2;
	while (j >= 0)
		c[j--] = str[i--];
	result = 0;
	j = 0;
	while (j <= i)
	{
		if (!('0' <= str[j] && str[j] <= '9'))
			return (0);
		result *= 10;
		result += str[j] - '0';
		j++;
	}
	if (!c_redun(c))
		return (0);
	return (result);
}

int	check_contents(char *str, char *c, int *size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c[0] && str[i] != c[1] && str[i] != '\n')
			return (0);
		if (str[i] == '\n')
		{
			if (str[i - 1] == '\n')
				return (0);
			if (str[i + 1] == '\n')
				return (0);
			if ((i + 1) % (size[1] + 1) != 0)
				return (0);
			count++;
		}
		i++;
	}
	if (count == size[0])
		return (1);
	return (0);
}

int	check_file(char *str, char *c, int *size)
{
	int	i;

	size[0] = first_line(str, c);
	if (size[0] <= 0)
		return (0);
	i = 0;
	while (str[i++] != '\n')
		;
	size[1] = 0;
	while (str[i++] != '\n')
		size[1]++;
	i = 0;
	while (str[i++] != '\n')
		;
	if (check_contents(str + i, c, size))
	{
		return (1);
	}
	return (0);
}
