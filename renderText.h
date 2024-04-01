#ifndef RENDER_TEXT_H 
#define  RENDER_TEXT_H
#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
void renderText(SDL_Renderer* renderer, int score); 
void init_texture(); 
void openFont(const char* fontPath); 
#endif
