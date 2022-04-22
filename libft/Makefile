NAME		=	libft.a

HEADER_PATH	=	includes/

SRCS_PATH	= 	srcs/

SRCS_LIST	=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c\
				ft_isascii.c	ft_isprint.c	ft_strlen.c\
				ft_memset.c		ft_bzero.c		ft_memcpy.c\
				ft_memmove.c	ft_strlcpy.c	ft_strlcat.c\
				ft_toupper.c	ft_tolower.c	ft_strchr.c\
				ft_strrchr.c	ft_strncmp.c	ft_memchr.c\
				ft_memcmp.c		ft_strnstr.c	ft_atoi.c\
				ft_calloc.c		ft_strdup.c		ft_substr.c\
				ft_strjoin.c	ft_putchar_fd.c	ft_putstr_fd.c\
				ft_putendl_fd.c	ft_putnbr_fd.c	ft_itoa.c\
				ft_strmapi.c	ft_striteri.c	ft_strtrim.c\
				ft_split.c		ft_isnumber.c

BSRCS_LIST	=	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
				ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
				ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

HEADER		=	$(addprefix $(HEADER_PATH), libft.h)

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_LIST))

BSRCS		= 	$(addprefix $(SRCS_PATH), $(BSRCS_LIST))

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

BOBJS		=	$(patsubst %.c, %.o, $(BSRCS))

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER_PATH)

RM		=	rm -f

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
	ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus	:
	@make OBJS="$(BOBJS)" all

clean	:
	$(RM) $(OBJS) $(BOBJS)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all