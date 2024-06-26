CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -rf

SRCS    = error.c init.c rotate_instractions.c push_instractions.c swap_instractions.c main.c radix_sort.c utils.c \
			mini_sort.c ft_substr.c long_sort.c long_sort_utils.c long_sort_utils2.c get_next_line_utils.c get_next_line.c
NAME    = push_swap

OBJ_DIR = obj/
SRC_DIR = src/
INCLUDE = -I inc/

SRCS_OBJS   = $(SRCS:.c=.o)
OBJS        = $(addprefix $(OBJ_DIR), $(SRCS_OBJS))

NAME_BONUS = checker
SRCS_BONUS = checker.c get_next_line.c get_next_line_utils.c rotate_instractions.c push_instractions.c swap_instractions.c \
			radix_sort.c init.c error.c utils.c
SRCS_BONUS_OBJS = $(SRCS_BONUS:.c=.o)
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(SRCS_BONUS_OBJS))


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_DIR) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME_BONUS) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all bonus

.PHONY: all clean fclean re