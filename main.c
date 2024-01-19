#include <SDL2/SDL.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#define WIDTH 800
#define HEIGHT 600
#define WIDTH_SNAKE 50
#define HEIGHT_SNAKE 50
#define DELAY 400
SDL_Window *window;
SDL_Renderer *renderer; 
struct Tail {
   int x; 
   int y; 
};
struct Snake {
     int x; 
     int y; 
     int direction; 
     int size; 
     int width; 
     int height; 
}; 
void renderSnake(struct Snake *snake, SDL_Renderer *renderer) {
       snake->x = 400; 
       snake->y = 400; 
       snake->direction = 0; 
       snake->size = 0; 
       snake->width = WIDTH_SNAKE; 
       snake->height = HEIGHT_SNAKE;
       SDL_Rect sn = {snake->x, snake->y, snake->width, snake->height}; 
       SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
       SDL_RenderFillRect(renderer, &sn); 
       SDL_RenderDrawRect(renderer, &sn);
       SDL_RenderPresent(renderer); // Update the rendering object  
}
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
     
     struct Snake snake; 
     
     SDL_Event event; 
     while (true) {
        // Main event Hendling Here // 	
	if (SDL_PollEvent(&event) < 0) {
		if (event.type == SDL_QUIT) 
			break; 	
	}
	renderSnake(&snake, renderer); 
	// Game play and Renderign gose here // 
	//
	//
	//
	//
	//
	//
	//
	// 
	//
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set the screen to blak 
	SDL_RenderClear(renderer); // Render and clear screen  
	SDL_RenderPresent(renderer); // Update the rendering object  
     }
     SDL_DestroyWindow(window); 
     SDL_Quit(); 
   return 0;
}
