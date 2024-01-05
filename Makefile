bon = so_long_bonus/

SRC = get_next_line.c get_next_line_utils.c my_malloc.c main.c \
	  utils.c ft_strchr.c ft_split.c ft_strlcpy.c flood_fill.c \
	  mlx.c point_img.c hook_mlx.c

SRCB = $(bon)get_next_line_bonus.c $(bon)get_next_line_utils_bonus.c $(bon)my_malloc_bonus.c \
	  $(bon)main_bonus.c $(bon)utils_bonus.c $(bon)ft_strchr_bonus.c \
	  $(bon)ft_split_bonus.c $(bon)ft_strlcpy_bonus.c $(bon)flood_fill_bonus.c \
	  $(bon)mlx_bonus.c $(bon)point_img_bonus.c $(bon)hook_mlx_bonus.c $(bon)ft_itoa_bonus.c \
	  $(bon)ft_putstr_fd.c

OBJ = ${SRC:.c=.o}

OBJB = ${SRCB:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = so_long

BNAME = so_bonus

all: ${NAME}

bonus: ${BNAME}

%_bonus.o : %_bonus.c $(bon)so_long_bonus.h $(bon)get_next_line_bonus.h $(bon)structs_bonus.h
			@echo "Compiling bonus $<"
			@${CC} ${FLAGS} -c $< -o $@

%o : %c so_long.h get_next_line.h structs.h
	@echo "Compiling $<"
	@${CC} ${FLAGS} -c $< -o $@


${NAME}: ${OBJ}
	@echo "Linking $@"
	${CC} ${FLAGS} ${OBJ} -Lmlx_dir -lmlx -framework OpenGL -framework AppKit -o $@

${BNAME}: ${OBJB}
	@echo "Linking bonus $@"
	${CC} ${FLAGS} ${OBJB} -Lmlx_dir -lmlx -framework OpenGL -framework AppKit -o $@

clean:
	@echo "Cleaning ..."
	rm -f ${OBJ} ${OBJB}

fclean:
	@echo "Full cleaning ..."
	rm -f ${OBJ} ${NAME} ${OBJB} ${BNAME}

re: clean all

.PHONY: clean fclean
