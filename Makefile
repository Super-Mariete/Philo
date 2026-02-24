NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g3
DFLAGS = -fsanitize=thread -g

SRCS = main.c \
       SRC/ft_control_error.c\
       SRC/utils_parse.c\
       SRC/ft_init_data.c\
       SRC/init_philos.c\
       SRC/aux_funtion.c\
       SRC/forks.c\
       SRC/threads.c\
       SRC/time.c\
       SRC/simulation.c\
       SRC/monitor.c\
       SRC/print_status.c\
       SRC/meal_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
