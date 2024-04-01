#include "Enermy.h" 
Enermy CreateEnermy(int x, int y, int width, int height, int speed) {
    Enermy enermy = {x, y, width, height, speed};
    return enermy;
}
const char* enPath = "art/player.bmp";
SDL_Surface* enermySurface = NULL; 
SDL_Texture* texture = NULL; 
SDL_Texture* enermyTexture(SDL_Renderer* renderer) {		
	SDL_Surface* enermySurface = SDL_LoadBMP("art/player.bmp"); 
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, enermySurface);	
	if (!enermySurface && !texture) {
		perror("Error Can't load the bit map(Enermy)\n");  
	} 
	return texture; 	
	SDL_FreeSurface(enermySurface); 
} 


