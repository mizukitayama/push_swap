CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -rf

SRCS    = error.c init.c rotate_instractions.c push_instractions.c swap_instractions.c main.c radix_sort.c utils.c mini_sort.c ft_split.c ft_substr.c
NAME    = push_swap

OBJ_DIR = obj/
SRC_DIR = src/
INCLUDE = -I inc/

SRCS_OBJS   = $(SRCS:.c=.o)
OBJS        = $(addprefix $(OBJ_DIR), $(SRCS_OBJS))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

clean:
	$(RM) $(OBJS) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re