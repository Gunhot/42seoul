/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:21:28 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/18 21:54:42 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	d_len;
	unsigned int	s_len;

	d_len = my_strlen2(dest);
	s_len = my_strlen2(src);
	if (size <= d_len)
		return (s_len + size);
	i = 0;
	while (i < size - d_len - 1 && src[i] != '\0')
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (s_len + d_len);
}
