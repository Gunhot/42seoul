/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:34:02 by kun-lee           #+#    #+#             */
/*   Updated: 2023/02/01 09:27:26 by hwayu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_function.h"

int	ret_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	all_len(int size, char **strs, char *sep)
{
	int	i;
	int	result;
	int	sep_len;

	sep_len = ret_len(sep);
	result = 0;
	i = 0;
	while (i < size)
	{
		result += ret_len(strs[i]);
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
		mystrncpy(result + start, strs[i], ret_len(strs[i]));
		start += ret_len(strs[i]);
		if (i < size - 1)
		{
			mystrncpy(result + start, sep, ret_len(sep));
			start += ret_len(sep);
		}
		i++;
	}
	result[result_len] = '\0';
	return (result);
}
