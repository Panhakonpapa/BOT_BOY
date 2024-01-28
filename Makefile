# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -lm

# SDL flags
SDL_FLAGS = -lSDL2 

# Source and output files
SRC = main.c  
OUT = game 

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) $(SDL_FLAGS)

clean:
	rm -f $(OUT)
