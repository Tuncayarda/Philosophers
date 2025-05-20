NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

SRC_FILES = srcs/checkErrors.c srcs/init.c srcs/lib_utils.c \
			srcs/main.c srcs/monitor.c srcs/routine_utils.c \
			srcs/routine.c srcs/utils.c
OBJ_FILES = $(SRC_FILES:.c=.o)

OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRC_FILES))
INCLUDE = includes/*.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) \
	-I includes \
	-o $(NAME)

objs/%.o: srcs/%.c
	mkdir -p objs
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	rm -rf objs/

fclean: clean
	rm -rf philo

re: fclean all

.PHONY: all clean fclean re