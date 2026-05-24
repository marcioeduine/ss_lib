# **************************************************************************** #
#                                                                              #
#                                                        ::::::::   ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+        +:+           #
#    By: Ser Superior <marcioeduine@gmail.com>       +#++:++#++ +#++:++#++     #
#                                                          +#+        +#+      #
#    Created: 2026/05/23 23:39:09 by Ser Superior  #+#    #+# #+#    #+#       #
#    Updated: 2026/05/24 16:21:40 by Ser Superior ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ss_samples.a
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -I../includes
XXD			= xxd -i
HEADER		= ../includes/Sample.hpp
OBJ			= sample_main.o
BIN			= sample_main

WAVS		= snare.wav kick.wav clap.wav hat.wav drum.wav open_hat.wav crash.wav rim.wav cowbell.wav conga.wav shaker.wav \
			  piano_c4.wav piano_cs4.wav piano_d4.wav piano_ds4.wav piano_e4.wav piano_f4.wav piano_fs4.wav piano_g4.wav piano_gs4.wav piano_a4.wav piano_as4.wav piano_b4.wav piano_c5.wav
HEADERS		= $(WAVS:.wav=.h)

all: $(NAME)

$(BIN): $(OBJ) ../ss_sound_script.a
	@$(CXX) $(CXXFLAGS) $^ -o $@

wavs.stamp: $(BIN)
	@./$(BIN)
	@touch $@

$(WAVS): wavs.stamp

%.h: %.wav
	@$(XXD) $< > $@

$(NAME): $(HEADERS)
	@ar rcs $@ $^

clean:
	@rm -f $(OBJ) $(BIN) $(HEADERS) $(WAVS) wavs.stamp

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re