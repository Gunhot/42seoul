CC = gcc
NAME = BSQ
SRCS = *.c
CFLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAG) -o $(NAME) $(SRCS)

clean :

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
