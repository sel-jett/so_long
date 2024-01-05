bon = so_long_bonus/

SRC = get_next_line.c get_next_line_utils.c my_malloc.c main.c \
	  utils.c ft_strchr.c ft_split.c ft_strlcpy.c flood_fill.c \
	  mlx.c point_img.c hook_mlx.c ft_itoa.c

SRCB = $(bon)get_next_line_bonus.c $(bon)get_next_line_utils_bonus.c $(bon)my_malloc_bonus.c \
	  $(bon)main_bonus.c $(bon)utils_bonus.c $(bon)ft_strchr_bonus.c \
	  $(bon)ft_split_bonus.c $(bon)ft_strlcpy_bonus.c $(bon)flood_fill_bonus.c \
	  $(bon)mlx_bonus.c $(bon)point_img_bonus.c $(bon)hook_mlx_bonus.c $(bon)ft_itoa_bonus.c

OBJ = ${SRC:.c=.o}

OBJB = ${SRCB:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = so_long

BNAME = so_bonus

bonus: ${BNAME}

all: ${NAME} clean

%_bonus.o : %_bonus.c $(bon)so_long_bonus.h $(bon)get_next_line_bonus.h $(bon)structs_bonus.h
	${CC} ${FLAGS} -Imlx -c $< -o $@

%o : %c so_long.h get_next_line.h structs.h
	${CC} ${FLAGS} -Imlx -c $< -o $@


${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -Lmlx_dir -lmlx -framework OpenGL -framework AppKit -o $@

${BNAME}: ${OBJB}
	${CC} ${FLAGS} ${OBJB} -Lmlx_dir -lmlx -framework OpenGL -framework AppKit -o $@

clean:
	rm -f ${OBJ} ${OBJB}

fclean:
	rm -f ${OBJ} ${NAME} ${OBJB} ${BNAME}

re: clean all

.PHONY: clean fclean
