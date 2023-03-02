CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJECTS = ${SRCS:.c=.o}

AR = ar -rc


INC = ./includes/
HEADER = ft.h

NAME = libft.a
all : $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INC)

clean :
	rm -f $(OBJECTS)
	
fclean	: clean
	rm -f $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
