#include "map.h"
const char* spritePath = "art/mapRobo.bmp";
SDL_Surface* spriteSurface = NULL;
SDL_Texture* spriteTexture = NULL; 
SDL_Texture* Texture(SDL_Renderer* renderer) {
	spriteSurface = SDL_LoadBMP(spritePath);
	if (spriteSurface == NULL) {
		perror("Error spritePath can't open\n"); 
	}
	spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteSurface);
	if (spriteTexture == NULL) {		
		perror("Error sprite renderer can't laod\n"); 
	}	
	SDL_FreeSurface(spriteSurface); 
	return spriteTexture; 
}
