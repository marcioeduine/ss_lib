NAME = ss_samples.a
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
XXD = xxd -i
HEADER = Sample.hpp
OBJ = Sample.o sample_main.o
BIN = sample_main

WAVS = snare.wav kick.wav clap.wav hat.wav drum.wav open_hat.wav crash.wav rim.wav cowbell.wav conga.wav shaker.wav
HEADERS = $(WAVS:.wav=.h)

all: $(NAME)

$(BIN): $(OBJ)
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