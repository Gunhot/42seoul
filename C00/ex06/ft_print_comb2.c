/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:35:03 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/14 22:34:10 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	inv(char *a)
{
	while (a[0] <= '9')
	{
		while (a[1] <= '9')
		{
			a[3] = a[0];
			a[4] = a[1] + 1;
			while (a[3] <= '9')
			{
				while (a[4] <= '9')
				{
					if (a[0] == '9' && a[1] == '8')
						write(1, a, 5);
					else
						write (1, a, 7);
					a[4]++;
				}
				a[3]++;
				a[4] = '0';
			}
			a[1]++;
		}
		a[0]++;
		a[1] = '0';
	}
}

void	ft_print_comb2(void)
{
	char	a[7];

	a[0] = '0';
	a[1] = '0';
	a[2] = ' ';
	a[5] = ',';
	a[6] = ' ';
	inv(a);
}
