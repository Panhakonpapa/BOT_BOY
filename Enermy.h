#ifndef ENERMY_H 
#define ENERMY_H 
#include <stdio.h>
#include <SDL2/SDL.h> 
typedef struct {
    int x;
    int y;
    int width;
    int height;
    int speed; 
} Enermy;
Enermy CreateEnermy(int x, int y, int width, int height, int speed); 
SDL_Texture* enermyTexture(SDL_Renderer* renderer); 
#endif 

