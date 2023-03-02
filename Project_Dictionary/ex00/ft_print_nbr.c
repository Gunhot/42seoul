/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeheeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:52:03 by jaeheeki          #+#    #+#             */
/*   Updated: 2023/01/29 22:41:31 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_function.h"

int	valid_check(char *str)
{
	if (str_len_func(str) > 39)
	{
		write(1, "Dict Error", 10);
		return (1);
	}
	if (str[0] == '0' && str_len_func(str) != 1)
	{
		write(1, "Error", 5);
		return (1);
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			write(1, "Error", 5);
			return (1);
		}
		str++;
	}
	return (0);
}

int	str_len_func(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	print_element(char *str, int element_len, t_node *head)
{
	char	*element;

	element = (char *)malloc(sizeof(char) * 4);
	if (element_len == 3)
	{
		element_len_3_search(str, element, head);
		element_len--;
		str++;
	}
	if (element_len == 2)
	{
		element_len_2_search(str, element, head);
		if (*str == '1')
		{
			free(element);
			return ;
		}
		element_len--;
		str++;
	}
	if (element_len == 1)
		element_len_1_search(str, element, head);
	free(element);
}

void	print_section(int section, t_node *head)
{
	int		count;
	char	*section_arr;

	section_arr = (char *)malloc(sizeof(char) * section * 3 + 2);
	section_arr[0] = '1';
	count = 1;
	while (count < section * 3 + 1)
	{
		section_arr[count] = '0';
		count++;
	}
	section_arr[count] = '\0';
	ft_search(section_arr, head);
	free(section_arr);
}

void	ft_print_nbr(char *str, t_node *head)
{
	int	str_len;
	int	element_len;
	int	section;

	str_len = str_len_func(str);
	section = (str_len - 1) / 3 + 1;
	if (valid_check(str))
		return ;
	if (str_len == 1 && *str == '0')
	{
		ft_search("0", head);
		return ;
	}
	while (--section >= 0)
	{
		element_len = str_len % 3;
		if (element_len == 0)
			element_len = 3;
		print_element(str, element_len, head);
		if (section != 0
			&& !(*str == '0' && *(str + 1) == '0' && *(str + 2) == '0'))
			print_section(section, head);
		str = str + element_len;
		str_len -= element_len;
	}
}
