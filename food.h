#ifndef FOOD_H 
#define FOOD_H 
#include <stdio.h>
#include <SDL2/SDL.h>
typedef struct {
    int x;
    int y;
    int width; 
    int height;
} Food;
Food CreateFood(int x, int y, int width, int height); 
SDL_Texture* foodTexture(SDL_Renderer* renderer); 
#endif 

