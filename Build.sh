#!bin/bash

# Compiler Options
COMPILERCPP="g++"
COMPILERC="gcc"
MAIN="main.c"
OUTPUT="video_game"
COMPILER_FLAGS="-Wall -Wextra -std=c11 -lm"
SDL_LIKER="-lSDL2 -lSDL2_ttf"

# Build the project
$COMPILERC $MAIN -o $OUTPUT $COMPILER_FLAGS $SDL_LIKER

# Check if the build was successful
if [ $? -eq 0 ]; then
    echo "Build successful! Executable: $OUTPUT"
else
    echo "Build failed."
fi

#gcc main.c -o game -Wall -Wextra -std=c11 -lm -lSDL2 -lSDL2_ttf 
