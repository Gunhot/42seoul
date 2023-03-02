/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:29:02 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/29 17:29:15 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_function.h"

int	checkspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

char	*my_strndup(char *src, int n)
{
	char	*dest;
	int		s_i;
	int		d_i;

	if (n == 0)
		return (0);
	while (checkspace(src[n - 1]))
		n--;
	dest = (char *)malloc(sizeof(char) * (n + 1));
	s_i = 0;
	d_i = 0;
	while (checkspace(src[s_i]))
		s_i++;
	while (s_i < n)
	{
		dest[d_i++] = src[s_i++];
	}
	dest[d_i] = '\0';
	return (dest);
}

t_node	*makenode(char *n, char *str)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	temp->num = n;
	temp->contents = str;
	temp->next = 0;
	return (temp);
}

int	find_index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

t_node	*parsing(char *buffer)
{
	char	*n;
	char	*str;
	t_node	*head;
	t_node	*new;
	int		i;

	head = makenode(0, 0);
	i = 0;
	while (buffer[i])
	{
		n = my_strndup(buffer + i, find_index_of(buffer + i, ':'));
		i += find_index_of(buffer + i, ':') + 1;
		str = my_strndup(buffer + i, find_index_of(buffer + i, '\n'));
		i += find_index_of(buffer + i, '\n') + 1;
		new = makenode(n, str);
		new -> next = head;
		head = new;
	}
	free(buffer);
	return (head);
}
