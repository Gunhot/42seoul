/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:21:28 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/18 21:54:15 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	d_len;
	unsigned int	s_len;

	d_len = my_strlen(dest);
	s_len = my_strlen(src);
	i = 0;
	while (i < n && i < s_len)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (dest);
}
