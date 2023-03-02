/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:42:07 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/29 22:14:47 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_function.h"

t_node	*open_file(char *filename)
{
	char	*buffer;
	char	c;
	int		buf_len;
	int		fd_in;
	int		i;

	i = 0;
	fd_in = open(filename, O_RDONLY);
	if (fd_in == -1)
	{
		return (0);
	}
	buf_len = 0;
	while (read(fd_in, &c, 1))
		buf_len++;
	buffer = (char *)malloc(sizeof(char) * (buf_len + 1));
	close(fd_in);
	fd_in = open(filename, O_RDONLY);
	read(fd_in, buffer, buf_len);
	close(fd_in);
	buffer[buf_len] = '\0';
	return (parsing(buffer));
}

int	my_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	free_all(t_node *head)
{
	t_node	*del;

	while (head)
	{
		del = head;
		head = head->next;
		if (del->contents)
			free(del->contents);
		if (del->num)
			free(del->num);
		del->next = 0;
		free(del);
	}
}

int	main(int argc, char **argv)
{
	t_node	*head;

	if (argc == 2)
	{
		head = open_file("./numbers.dict");
		if (head)
			ft_print_nbr(argv[1], head);
	}
	else if (argc == 3)
	{	
		head = open_file(argv[1]);
		if (head)
			ft_print_nbr(argv[2], head);
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (head)
		free_all(head);
	else
		write(1, "Dict Error", 10);
	write(1, "\n", 1);
	return (0);
}
