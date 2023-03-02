/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <kun-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:46:12 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/18 20:35:13 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase2(char *str)
{
	int	i;
	int	offset;

	offset = 'a' - 'A';
	i = 0;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			str[i] += offset;
		}
		i++;
	}
	return (str);
}

int	word_check(char c)
{
	if ('a' <= c && c <= 'z')
		return (3);
	else if ('A' <= c && c <= 'Z')
		return (2);
	else if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	offset;
	int	i;

	ft_strlowcase2(str);
	offset = 'a' - 'A';
	i = 0;
	while (str[i] != '\0')
	{
		if (!word_check(str[i - 1]))
			if (word_check(str[i]) == 3)
				str[i] -= offset;
		i++;
	}
	return (str);
}
