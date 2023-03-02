/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:41:58 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/25 17:49:22 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_check(char *base)
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

long	base_atoi(char *str, char *base, long bn)
{
	long	result;
	int		i;
	int		j;

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

long	nbr_to_int(char *str, char *base, int bn)
{
	long	result;
	int		i;
	int		count;

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
char	*int_to_string(long nbr, char *base, int t_bn);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	long	stopover;
	int		f_bn;
	int		t_bn;

	f_bn = base_check(base_from);
	t_bn = base_check(base_to);
	if (!f_bn || !t_bn)
		return (0);
	stopover = nbr_to_int(nbr, base_from, f_bn);
	result = int_to_string(stopover, base_to, t_bn);
	return (result);
}
