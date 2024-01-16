#include <SDL2/SDL.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#define WIDTH 800
#define HEIGHT 600

SDL_Window *window;
SDL_Renderer *renderer; 
int main() { 
    printf("Initing the SDL_INTI SYSTEM...\n");  
    SDL_Init(SDL_INIT_EVERYTHING); 
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
	printf("Someting went wrong with SDL_INIT...\n"); 
    }
    window = SDL_CreateWindow(
	NULL, 
	SDL_WINDOWPOS_UNDEFINED, //  position x  	
	SDL_WINDOWPOS_UNDEFINED, // position y  
        WIDTH, // Width window  
	HEIGHT, // Height window  
	0); // 0 is the flags
     if (window == NULL) {
	printf("There is no window UwU... \n");	
     }
     renderer = SDL_CreateRenderer(
                   window, // Rendering window  
	           -1, // set flags to -1  
		   SDL_RENDERER_ACCELERATED // using graphic to drawing window
		   ); 
     SDL_Event event; 
     while (true) {
	if (SDL_PollEvent(&event) < 0) {
		if (event.type == SDL_QUIT) 
			break; 	
	}
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
	SDL_RenderClear(renderer); 
	SDL_RenderPresent(renderer); 
     }
     SDL_DestroyWindow(window); 
     SDL_Quit(); 
   return 0;
}
