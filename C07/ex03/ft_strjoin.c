/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:30:46 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/25 12:02:12 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len_of(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	all_len(int size, char **strs, char *sep)
{
	int	i;
	int	result;
	int	sep_len;

	sep_len = len_of(sep);
	result = 0;
	i = 0;
	while (i < size)
	{
		result += len_of(strs[i]);
		if (i < size - 1)
			result += sep_len;
		i++;
	}
	return (result);
}

void	mystrncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		result_len;
	int		start;

	result_len = all_len(size, strs, sep);
	result = (char *)malloc(sizeof(char) * result_len + 1);
	start = 0;
	i = 0;
	while (i < size)
	{
		mystrncpy(result + start, strs[i], len_of(strs[i]));
		start += len_of(strs[i]);
		if (i < size - 1)
		{
			mystrncpy(result + start, sep, len_of(sep));
			start += len_of(sep);
		}
		i++;
	}
	result[result_len] = '\0';
	return (result);
}
