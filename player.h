#ifndef PLAYER_H 
#define PLAYER_H 
#include <SDL2/SDL.h> 
typedef struct {
    int x;
    int y;
    int width; 
    int height;
} Player;
SDL_Texture* PlayerTexture(SDL_Renderer* renderer);
void playerMovement(Player *player, int dx, int dy); 
Player Createplayer(int x, int y, int width, int height);  
#endif 
