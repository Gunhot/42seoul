/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:30:02 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/26 20:39:16 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_str(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] && check_sep(str[i], charset))
		i++;
	while (str[i])
	{
		if (!check_sep(str[i], charset)
			&& (check_sep(str[i + 1], charset) || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	*len_each(char *str, char *charset, int str_count)
{
	int	*each_len;
	int	i;
	int	j;

	each_len = (int *)malloc(sizeof(int) * str_count);
	i = 0;
	while (i < str_count)
		each_len[i++] = 0;
	i = 0;
	while (str[i] && check_sep(str[i], charset))
		i++;
	j = 0;
	while (str[i])
	{
		if (!check_sep(str[i], charset))
		{
			each_len[j]++;
		}
		else if (!check_sep(str[i + 1], charset))
			j++;
		i++;
	}
	return (each_len);
}

void	mystrncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**splited;
	int		*each_len;
	int		str_count;
	int		i;
	int		j;

	str_count = count_str(str, charset);
	splited = (char **)malloc(sizeof(char *) * str_count + 1);
	each_len = len_each(str, charset, str_count);
	i = -1;
	while (++i < str_count)
		splited[i] = (char *)malloc(sizeof(char) * each_len[i] + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!check_sep(str[i], charset))
		{
			mystrncpy(splited[j], str + i, each_len[j]);
			i += each_len[j++];
		}
		i++;
	}
	splited[str_count] = NULL;
	return (splited);
}
