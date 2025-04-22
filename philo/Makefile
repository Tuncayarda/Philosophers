NAME = philo
CC = cc
#CFLAGS = -Wall -Wextra -Werror

SRC_FILES = $(wildcard srcs/*.c)
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