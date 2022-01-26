NAME 	= pipex

SRCS 	= pipex.c utils.c utils2.c ft_split.c
OBJS 	= $(SRCS:.c=.o)
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) 

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
