NAME	= ss_lib.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -std=c99
HEADER	= ss_lib.h
OBJ		= ss_putchar_fd.o ss_putendl_fd.o ss_putnbr_fd.o ss_putstr_fd.o \
		ss_strlen.o ss_isalpha.o ss_isdigit.o ss_isalnum.o ss_isascii.o \
		ss_isprint.o ss_islower.o ss_isspace.o ss_isupper.o ss_strtrim.o \
		ss_split.o ss_strchr.o ss_strrchr.o ss_strdup.o ss_substr.o \
		ss_world_counter.o ss_calloc.o ss_memset.o ss_free_matrix.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(HEADER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
