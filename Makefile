# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -lm

# SDL flags
SDL_FLAGS = -lSDL2

# Directories
LIB_DIR = game_libs

# Source and output files
SRC = main.c
OUT = game

# Header files
HEADERS = $(wildcard $(LIB_DIR)/*.h)

all: $(OUT)

$(OUT): $(SRC) $(HEADERS)
	@mkdir -p $(LIB_DIR)
	$(CC) $(CFLAGS) -o $(OUT) -I$(HEADERS) $(SDL_FLAGS)

clean:
	rm -rf $(OUT)

