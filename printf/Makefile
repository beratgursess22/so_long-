NAME = libftprintf.a
GCC = cc
AR = ar rc
RM  = rm -rf 
CFLAGS = -Wall -Wextra -Werror 

SRCS = ft_basic1.c ft_basic2.c ft_printf.c


OBJS = ${SRCS:.c=.o}

all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re 