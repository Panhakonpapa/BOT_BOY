# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra

# SDL flags
SDL_FLAGS = -lSDL2

# Source and output files
SRC = main.c  
OUT = window 

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) $(SDL_FLAGS)

clean:
	rm -f $(OUT)
