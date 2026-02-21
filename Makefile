NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g3

SRCS = main.c \
       SRC/ft_control_error.c\
       SRC/utils_parse.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
