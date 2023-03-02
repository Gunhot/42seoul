CC = gcc
NAME = do-op
CFLAGS = -Wall -Werror -Wextra
SRCS = ./main.c ./calculate.c

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean :

fclean : clean
	rm -rf $(NAME)

re : fclean all
