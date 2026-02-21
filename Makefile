NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g3

SRCS = main.c \
       SRC/ft_control_error.c\
       SRC/utils_parse.c\
       SRC/ft_init_data.c\
       SRC/init_philos.c\
       SRC/aux_funtion.c\
       SRC/init_forks.c\
       SRC/simulate.c\
       SRC/threads.c

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
