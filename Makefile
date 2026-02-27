# **************************************************************************** #
#                                                                              #
#                                                         ::::::::   ::::::::  #
#      Makefile                                         :+:    :+: :+:    :+:  #
#                                                      +:+        +:+          #
#      By: Ser Superior <marcioeduine@gmail.com>      +#++:++#++ +#++:++#++    #
#                                                           +#+        +#+     #
#      Created: 2026/02/27 17:47:03 by Ser Superior #+#    #+# #+#    #+#      #
#      Updated: 2026/02/27 22:13:31 by Ser Superior ########   ########        #
#                                                                              #
# **************************************************************************** #

NAME	= ss_lib.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -std=c99
HEADER	= ss_lib.h
OBJ		= ss_putchar_fd.o ss_putendl_fd.o ss_putnbr_fd.o ss_putstr_fd.o		   \
		ss_strlen.o ss_isalpha.o ss_isdigit.o ss_isalnum.o ss_isascii.o		   \
		ss_isprint.o ss_islower.o ss_isspace.o ss_isupper.o ss_strtrim.o	   \
		ss_split.o ss_strchr.o ss_strrchr.o ss_strdup.o ss_substr.o	ss_swap.o  \
		ss_world_counter.o ss_calloc.o ss_memset.o ss_free_matrix.o			   \
		ss_islower.o ss_isupper.o ss_totext.o ss_strljoin.o ss_isnumber_limit.o\
		ss_tonumber.o

all: $(NAME)

$(OBJ): $(HEADER)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

main: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o ss

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) ss

re: fclean all

.PHONY: all clean fclean re
