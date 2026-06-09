NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SOURCE = sort/simple/ft_simple.c \
	sort/medium/ft_medium_fill_b.c \
	sort/medium/ft_medium_max.c \
	sort/medium/ft_medium.c \
	sort/complex/ft_complex_utils.c \
	sort/complex/complex.c \
	utils/algorithm_general.c \
	utils/create_stack.c \
	utils/display_bench.c \
	utils/ft_split.c \
	utils/coordinate.c \
	utils/handel_input.c \
	utils/handel_option.c \
	utils/join_args.c \
	utils/main_utils.c \
	utils/main.c \
	utils/print_utils.c \
	utils/stack_operation.c \

OBJECTS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re