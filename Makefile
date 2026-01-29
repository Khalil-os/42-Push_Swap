NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	main.c \
		chunk_sort.c \
		small_sort.c \
		index.c \
		positions.c \
		stack.c \
		parse_args.c \
		split_utils.c \
		utils.c \
		op_push.c \
		op_swap.c \
		op_rotate.c \
		op_revrotate.c

OBJ = $(SRC:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re