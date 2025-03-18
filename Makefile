NAME = so_long

SRC =  actions.c check_error.c check_number.c free.c get_next_line.c get_next_line_utils.c  \
        images.c manage.c map.c player.c so_long.c

CC = cc

CFLAGS = -Wall -Wextra -Werror


OBJ = $(SRC:.c=.o)

LIBRARY = -Lmlx_linux -lmlx -lX11 -lXext -lm
MINILIBX = mlx_linux/
PRINTF = printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MINILIBX)
	@make -C printf
	@$(CC) $(CFLAGS) $(OBJ) $(LIBRARY) $(PRINTF) -o $(NAME)

clean:
	@make clean -C printf
	@make clean -C $(MINILIBX)
	@rm -f $(OBJ)

fclean: clean
	@make clean -C $(MINILIBX)
	@make fclean -C printf
	@rm -f $(NAME)

re: fclean all
