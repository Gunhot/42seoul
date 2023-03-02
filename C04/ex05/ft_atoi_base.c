/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:41:58 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/20 00:22:54 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_check2(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	base_atoi(char *str, char *base, unsigned int bn)
{
	int	result;
	int	i;
	int	j;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		result *= bn;
		j = 0;
		while (base[j] != str[i] && base[j] != '\0')
			j++;
		if (base[j] == '\0')
		{	
			result /= bn;
			break ;
		}
		else
			result += j;
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	bn;
	int	i;
	int	count;
	int	result;

	bn = base_check2(base);
	if (!bn)
		return (0);
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	count = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	result = base_atoi(str + i, base, bn);
	if (count % 2)
		return (-result);
	return (result);
}
