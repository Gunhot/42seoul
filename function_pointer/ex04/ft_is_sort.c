/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:08:15 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/31 03:12:38 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	past;

	i = 0;
	past = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]))
		{
			if ((long)((long)past * (long)f(tab[i], tab[i + 1])) < 0)
				return (0);
			past = f(tab[i], tab[i + 1]);
		}
		i++;
	}
	return (1);
}
