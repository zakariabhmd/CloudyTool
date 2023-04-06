SRCS	=  get_next_line_utils.c get_next_line.c\

OBJS	= ${SRCS:.c=.o}

NAME	= get_next_line.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

all : ${NAME}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean :
	${RM} ${OBJS}

fclean :
	${RM} ${NAME} ${OBJS}

re : fclean all
