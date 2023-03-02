/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_function.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kun-lee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:53:39 by kun-lee           #+#    #+#             */
/*   Updated: 2023/02/01 12:33:59 by kun-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_FUNCTION_H
# define ALL_FUNCTION_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_size_coord
{
	int			x;
	int			y;
	int			size;
}				t_size_coord;
char			*readfile(char *filename);
int				check_contents(char *str, char *c, int *size);
int				first_line(char *str, char *c);
int				check_file(char *str, char *c, int *size);
int				**convert_map(char *file, char *c, int *size);
int				**make_map(char *str, char *c, int *size);
int				**make_sizedmap(int size[]);
int				get_min(int a, int b, int c);
int				**calc_size(int **map, int *size);
void			print_map(int **map, char *c, int *size);
t_size_coord	get_max_size(int **sized_map, int size[]);
void			draw(int **map, int **sized_map, char *c, int *size);
int				find_size_one(char *str);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*read_file(char *c, int *size);
void			exception(char *c, int *size);
char			*ft_strdup(char *src);
int				ret_len(char *str);
int				check_buffer(char *buffer, char *c, int size_one);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
int				find_size_one(char *str);
char			*ft_strjoin(int size, char **strs, char *sep);
void			mystrncpy(char *dest, char *src, int n);
int				all_len(int size, char **strs, char *sep);
int				c_redun(char *c);
void			free_double_char(char **str, int n);
void			free_double_int(int **arr, int n);
void			free_all(int **map, int **sized_map, int n);

#endif
