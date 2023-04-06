SRCS	= ft_putstr.c ft_putnbr.c ft_putchar.c ft_adresse.c ft_numberh.c ft_printf.c \
ft_putnbr_uns.c \

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

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
