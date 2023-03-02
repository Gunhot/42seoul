/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:23:46 by kun-lee           #+#    #+#             */
/*   Updated: 2023/02/01 16:47:47 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_function.h"

int	find_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	check_buffer(char *buffer, char c[], int size_one)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] != c[0] && buffer[i] != c[1])
			return (0);
		i++;
	}
	if (i != size_one)
		return (0);
	return (1);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		s_len;
	int		i;

	s_len = ret_len(src);
	dest = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < s_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*read_file(char c[], int size[])
{
	int		i;
	char	buffer[4076];
	char	*result;
	char	**file;

	file = (char **)malloc(sizeof(char *) * size[0]);
	i = 0;
	while (i < size[0])
	{
		read(1, buffer, 4076);
		*(buffer + find_new_line(buffer)) = '\0';
		if (i == 0)
			size[1] = ret_len(buffer);
		if (size[1] != ret_len(buffer))
			return (0);
		if (!check_buffer(buffer, c, size[1]))
			return (0);
		buffer[size[1]] = '\0';
		file[i] = ft_strdup(buffer);
		i++;
	}
	result = ft_strjoin(size[0], file, "\n");
	free_double_char(file, size[0]);
	return (result);
}

void	exception(char *c, int size[])
{
	char	buffer[4076];
	int		**map;
	int		**sized_map;
	char	*file;

	read(1, buffer, 4076);
	size[0] = first_line(buffer, c);
	if (size[0] > 0)
		file = read_file(c, size);
	if (size[0] <= 0 || !file)
	{
		write(1, "map error\n", 10);
		return ;
	}
	map = convert_map(file, c, size);
	free(file);
	sized_map = calc_size(map, size);
	draw(map, sized_map, c, size);
	free_all(map, sized_map, size[0]);
}
