CC	= cc

CFLAGS	= -Wall -Wextra -Werror -I.

SRC_DIR = srcs
OBJ_DIR = objs

SRC =	$(SRC_DIR)/philosophers.c \
		$(SRC_DIR)/ft_check_int.c \
		$(SRC_DIR)/ft_init.c \
		$(SRC_DIR)/ft_thread.c \
		$(SRC_DIR)/ft_time.c \
		$(SRC_DIR)/ft_etat.c \
		$(SRC_DIR)/ft_get.c

OBJ = ${SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o}

NAME	= philo

all	: ${NAME}

${NAME}	: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -rf	$(OBJ_DIR)

fclean	:	clean
	rm	-f	$(NAME)

re	:	fclean all

.PHONY: all clean fclean re