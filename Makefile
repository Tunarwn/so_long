MINILIBX	= minilibx/libmlx.a
CC 			= gcc
FLAGS 		= -Wall -Wextra -Werror
NAME 		= so_long	
LFLAGS		= -framework OpenGL -framework AppKit
SRCS		= src/utils_1.c src/main.c src/ft_split.c src/create.c src/hareket.c
OBJ			= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) :  $(OBJ) $(MINILIBX)
	$(CC) $(FLAGS)  $(OBJ) $(LFLAGS) -o $(NAME) minilibx/libmlx.a ft_printf/libftprintf.a

$(MINILIBX):
	make -C minilibx
	@echo "\033[0;95mMINILIBX compile OLDU"

run :all
	./$(NAME) maps/map1.ber
re : fclean all
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

norm:
	norminette src/*.C
	norminette *.h
	norminette ft_printf/*.c
