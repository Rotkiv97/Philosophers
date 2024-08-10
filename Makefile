NAME        := philo
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -g -pthread

SRCS        :=      main.c \
                          ft_check.c \
                          ft_utils.c \
						  ft_get_time.c \
						  ft_vita.c \
						  ft_free.c\
						  ft_get_def_print.c\
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

RM		    := rm -f

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o

fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all
