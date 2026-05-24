# **************************************************************************** #
#                                                                              #
#                                                        ::::::::   ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+        +:+           #
#    By: Ser Superior <marcioeduine@gmail.com>       +#++:++#++ +#++:++#++     #
#                                                          +#+        +#+      #
#    Created: 2026/05/23 16:09:49 by Ser Superior  #+#    #+# #+#    #+#       #
#    Updated: 2026/05/23 16:10:00 by mcaquart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ss_lib.a
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
HEADER		= includes/SoundScript.hpp includes/miniaudio.h
OBJ			= srcs/SoundScript.o srcs/utilities.o

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJ): $(HEADER)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
