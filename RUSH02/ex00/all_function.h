/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_function.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:23:00 by kun-lee           #+#    #+#             */
/*   Updated: 2023/01/29 22:13:32 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_FUNCTION_H
# define ALL_FUNCTION_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*next;
	char			*num;
	char			*contents;
}	t_node;

int		checkspace(char c);
char	*my_strndup(char *src, int n);
t_node	*makenode(char *n, char *str);
int		find_index_of(char *str, char c);
t_node	*parsing(char *buffer);
t_node	*open_file(char *filename);
int		my_strcmp(char *s1, char *s2);
char	*search_in_num(t_node *head, char *str);
void	free_all(t_node *head);
void	ft_search(char *str, t_node *head);
void	element_len_3_search(char *str, char *element, t_node *head);
void	element_len_2_search(char *str, char *element, t_node *head);
void	element_len_1_search(char *str, char *element, t_node *head);
int		valid_check(char *str);
int		str_len_func(char *str);
void	print_element(char *str, int element_len, t_node *head);
void	print_section(int section, t_node *head);
void	ft_print_nbr(char *str, t_node *head);

#endif
