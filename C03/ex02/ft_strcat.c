/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:21:28 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/18 21:49:24 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	d_len;
	int	s_len;

	i = 0;
	while (dest[i] != '\0')
		i++;
	d_len = i;
	i = 0;
	while (src[i] != '\0')
		i++;
	s_len = i;
	i = d_len;
	while (i < d_len + s_len)
	{
		dest[i] = src[i - d_len];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
