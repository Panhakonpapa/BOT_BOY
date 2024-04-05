#include "food.h" 
Food CreateFood(int x, int y, int width, int height) { 
    Food food = {x, y, width, height};
    return food;
}
const char* foodPath = "art/food.bmp";
SDL_Surface* foodSurface = NULL; 
SDL_Texture* footexture = NULL; 
SDL_Texture* foodTexture(SDL_Renderer* renderer) {			
	SDL_Surface* foodSurface = SDL_LoadBMP(foodPath); 
	SDL_Texture* footexture = SDL_CreateTextureFromSurface(renderer, foodSurface);	
	if (!foodSurface && !footexture) {
		perror("Error Can't load the bit map(Enermy)\n");  
	} 
	return footexture; 	
	SDL_FreeSurface(foodSurface); 
} 



