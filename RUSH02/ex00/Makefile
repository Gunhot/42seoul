CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./ft_print_nbr.c ./main.c ./parsing.c ./sub.c 
NAME = rush-02
all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean : 

fclean	: $(clean)
	rm -f $(NAME)

re	: fclean all
