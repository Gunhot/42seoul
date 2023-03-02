/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeheeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:39:50 by jaeheeki          #+#    #+#             */
/*   Updated: 2023/01/29 22:16:48 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_function.h"

void	ft_search(char *str, t_node *head)
{
	t_node	*current;

	current = head;
	while (current -> num)
	{
		if (!my_strcmp(str, current->num))
		{
			write(1, current->contents, str_len_func(current->contents));
			write(1, " ", 1);
			return ;
		}
		current = current -> next;
	}
	write(1, "Dict Error", 10);
	return ;
}

void	element_len_3_search(char *str, char *element, t_node *head)
{
	if (*str != '0')
	{
		*element = *str;
		*(element + 1) = '\0';
		ft_search(element, head);
		ft_search("100", head);
	}
}

void	element_len_2_search(char *str, char *element, t_node *head)
{
	if (*str != '0')
	{
		*element = *str;
		if (*str == '1')
			*(element + 1) = *(str + 1);
		else
			*(element + 1) = '0';
		*(element + 2) = '\0';
		ft_search(element, head);
	}
}

void	element_len_1_search(char *str, char *element, t_node *head)
{
	if (*str != '0')
	{
		*element = *str;
		*(element + 1) = '\0';
		ft_search(element, head);
	}
}
