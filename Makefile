CC	= cc

CFLAGS	= -Wall -Wextra -Werror

SRC =	philosophers.c \
		ft_check_int.c

OBJ = ${SRC:.c=.o}

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

NAME	= philo

all	: ${NAME}

${NAME}	: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}
	# ar -rcs $@ $^

clean	:
	rm -f	${OBJ}

fclean	:
	rm	-f	${NAME}

re	:	fclean
	make

.PHONY: all clean fclean re