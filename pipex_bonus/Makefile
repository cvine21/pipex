NAME		=	pipex

HEADER_NAME	=	pipex.h

INCLUDES	=	includes/

SRCS_DIR	=	srcs/

LIBFT		=	../libft/

SRCS_LST	=	parser.c	error.c		file_opener.c\
				heredoc.c	executor.c	main.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST))

HEADER		=	$(addprefix $(INCLUDES), $(HEADER_NAME))

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

CC			=	gcc	

CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDES) -I$(LIBFT)$(INCLUDES)

LIBFLAGS	=	-L$(LIBFT) -lft

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $@

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean		:	clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)

re			:	fclean all