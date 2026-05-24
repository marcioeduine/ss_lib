# **************************************************************************** #
#                                                                              #
#                                                        ::::::::   ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+        +:+           #
#    By: Ser Superior <marcioeduine@gmail.com>       +#++:++#++ +#++:++#++     #
#                                                          +#+        +#+      #
#    Created: 2026/05/23 16:09:49 by Ser Superior  #+#    #+# #+#    #+#       #
#    Updated: 2026/05/24 16:21:30 by Ser Superior ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ss_sound_script.a
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iincludes
HEADER		= includes/SoundScript.hpp includes/miniaudio.h includes/Sample.hpp
OBJ			= srcs/SoundScript.o srcs/Sample.o

all: $(NAME)
	@make -C samples

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJ): $(HEADER)

clean:
	@rm -f $(OBJ)
	@make clean -C samples

fclean: clean
	@rm -f $(NAME)
	@make fclean -C samples

re: fclean all

.PHONY: all clean fclean re
