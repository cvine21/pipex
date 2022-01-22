NAME		=	pipex

SRCS_DIR	=	./srcs/

SRCS_LST	=	ft_split.c	parse.c		error.c\
				utils.c		print.c		pipex.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST))

HEADER		=	./includes/pipex.h

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	$(RM) $(OBJS)     

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all