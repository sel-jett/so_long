SRC = get_next_line.c get_next_line_utils.c my_malloc.c main.c \
	  utils.c ft_strchr.c ft_split.c ft_strlcpy.c flood_fill.c \
	  mlx.c point_img.c hook_mlx.c ft_itoa.c

OBJ = ${SRC:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = so_long

all: ${NAME} clean

%o : %c so_long.h get_next_line.h
	${CC} ${FLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -Lmlx_dir -lmlx -framework OpenGL -framework AppKit -o $@

clean:
	rm -f ${OBJ}

fclean:
	rm -f ${OBJ} ${NAME}

re: clean all

.PHONY: clean fclean
