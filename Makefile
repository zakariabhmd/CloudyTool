NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = so_long.c path.c map.c map2.c hooks.c hooks2.c graphics.c graphics2.c tools.c

SRCU = get_next_line/get_next_line.a ft_printf/libftprintf.a libft/libft.a

all: $(NAME)

$(NAME): $(SRC)
		@make -C libft
		@make -C get_next_line
		@make -C ft_printf
		@$(CC) $(CFLAGS) $(SRC) $(SRCU) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@make -C libft clean
	@make -C get_next_line clean
	@make -C ft_printf clean

fclean: clean
	@make -C libft fclean
	@make -C get_next_line fclean
	@make -C ft_printf fclean
	$(RM) $(NAME)

re: fclean all