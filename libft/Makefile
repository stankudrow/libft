NAME := libft.a
LIBSO := $(NAME:.a=.so) # for some testers

# Files
HEADER := $(NAME:.a=.h)

MSRCS := ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c
ASRCS := ft_substr.c ft_strjoin.c ft_strtrim.c \
ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
SRCS := $(MSRCS) $(ASRCS)
SRCS_BONUS := ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS := $(SRCS:.c=.o)
OBJS_BONUS := $(SRCS_BONUS:.c=.o)

# Compilation flags
CC := cc
CFLAGS := -Wall -Werror -Wextra

.PHONY: all clean fclean re so bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBSO)

re: fclean all

so: bonus
	$(CC) -nostartfiles -shared -o $(LIBSO) -fPIC $(SRCS) $(SRCS_BONUS)

bonus: $(NAME) $(OBJS_BONUS)
	ar urs $(NAME) $(OBJS_BONUS)