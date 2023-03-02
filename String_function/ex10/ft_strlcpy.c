/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:27:06 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/19 03:28:50 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	s_len;

	if (!src || !dest)
		return (0);
	i = 0;
	while (src[i] != '\0')
		i++;
	s_len = i;
	if (size == 0)
		return (s_len);
	i = 0;
	while (i < size - 1 && i < s_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (s_len);
}
