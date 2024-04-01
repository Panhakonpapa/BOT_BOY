#include "player.h" 
void playerMovement(Player *player, int dx, int dy) {
    player->x += dx;
    player->y += dy;
}
Player Createplayer(int x, int y, int width, int height) {
    Player player = {x, y, width, height};
    return player;
} 

const char* playerSurPath = "art/blop.bmp";  
SDL_Surface* playerSurface = NULL;	 
SDL_Texture* Texture = NULL;  
SDL_Texture* PlayerTexture(SDL_Renderer* renderer) {
	playerSurface = SDL_LoadBMP(playerSurPath);
	Texture = SDL_CreateTextureFromSurface(renderer,  playerSurface);
	if (!playerSurPath && !Texture) {
		perror("Error while loading bitma\n"); 
	}
	return Texture;
	SDL_FreeSurface(playerSurface);
}

