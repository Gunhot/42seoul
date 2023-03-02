/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:56:59 by kun-lee           #+#    #+#             */
/*   Updated: 2023/02/01 09:27:19 by hwayu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_function.h"

int	**convert_map(char *file, char *c, int *size)
{
	int	**map;
	int	i;
	int	j;
	int	k;

	map = (int **)malloc(sizeof(int *) * (size[0]));
	i = 0;
	j = -1;
	while (file[i])
	{
		if ((i % (size[1] + 1)) == 0)
		{
			k = 0;
			j++;
			map[j] = (int *)malloc(sizeof(int) * (size[1]));
		}
		if (file[i] == c[0])
			map[j][k] = 0;
		if (file[i] == c[1])
			map[j][k] = 1;
		k++;
		i++;
	}
	return (map);
}

char	*readfile(char *filename)
{
	char	*buffer;
	char	c;
	int		buf_len;
	int		fd_in;
	int		i;

	i = 0;
	fd_in = open(filename, O_RDWR);
	if (fd_in == -1)
		return (0);
	buf_len = 0;
	while (read(fd_in, &c, 1))
		buf_len++;
	if (buf_len < 5)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (buf_len + 1));
	close(fd_in);
	fd_in = open(filename, O_RDONLY);
	read(fd_in, buffer, buf_len);
	close(fd_in);
	buffer[buf_len] = '\0';
	return (buffer);
}

int	**make_map(char *str, char *c, int *size)
{
	char	*file;
	int		**map;
	int		i;

	file = readfile(str);
	if (!file)
		return (0);
	if (!check_file(file, c, size))
		return (0);
	i = 0;
	while (file[i++] != '\n')
		;
	map = convert_map(file + i, c, size);
	free(file);
	return (map);
}
