NAME = libftprintf.a

SRCS_MAND = ft_itoa.c ft_printf.c ft_putchar.c ft_putnbrhex.c ft_itoaunsigned.c ft_putnbrhexx.c ft_putstr.c

OBJS_MAND	= ${SRCS_MAND:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

all : $(NAME)

$(NAME) : $(OBJS_MAND)
	ar rcs $(NAME) $(OBJS_MAND)

clean :
	rm -rf $(OBJS_MAND)

fclean : clean
	rm -f $(NAME)

re : fclean all