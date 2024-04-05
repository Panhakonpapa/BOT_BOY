#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include "renderText.h"
#include "map.h"
#include "player.h"
#include "Enermy.h"
#include "food.h" 
#include "physics.h"
#include "gameover.h" 

#define WIDTH 800
#define HEIGHT 600
#define WIDTH_SNAKE 50
#define HEIGHT_SNAKE 50
#define ENERMY_WIDTH 50 
#define ENERMY_HEIGHT 50 
#define ENERMY_SPEED 5
#define DELAY 400
#define RIGHT 20 
#define LEFT -20
#define UP -20 
#define DOWN 20
#define DISTANCE_CONSTANT 200.0f

SDL_Window *window;
SDL_Renderer *renderer;
int main() {
    printf("Initing the SDL_INTI SYSTEM...\n");
    int score = 10; 
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Init(SDL_INIT_VIDEO);
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
	printf("Someting went wrong with SDL_INIT...\n"); 
        exit(EXIT_FAILURE);  
    }
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);  // Exit the program or handle the error accordingly
}

    window = SDL_CreateWindow(
	"BOT BOY",
	SDL_WINDOWPOS_UNDEFINED,  	
	SDL_WINDOWPOS_UNDEFINED, 
        WIDTH, 
	HEIGHT,
	0); 

     if (window == NULL) {
	printf("There is no window UwU... \n");	
     }

     renderer = SDL_CreateRenderer(
                   window, 
	           -1,
		   SDL_RENDERER_ACCELERATED 
		   );
      
    const char* fontPath = "/home/panha/sanke/Snake_Game/art/ErbosDraco1StNbpRegular-99V5.ttf";     	  
  
    init_texture();
    openFont(fontPath);

    init_texture2();
    openFont2(fontPath);
    
    SDL_Texture* Entexture = enermyTexture(renderer); 
    SDL_Texture* Playertexture = PlayerTexture(renderer);
    SDL_Texture* Mapping = mapTexture(renderer); 
    SDL_Texture* foodtexture = foodTexture(renderer); 
          
    Food food = CreateFood(300, 300, 50, 50); 
    Player player = Createplayer(100, 100, 50, 50); 
    Enermy enermy = CreateEnermy(200, 200, 50, 50, 1);  
     
     SDL_Event event;
     while (true) {
	if (SDL_PollEvent(&event) < 0) {
		if (event.type == SDL_QUIT)
		return -1; 	
	}	
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if (currentKeyStates[SDL_SCANCODE_UP]) {
            playerMovement(&player, 0, UP);
        }
        if (currentKeyStates[SDL_SCANCODE_DOWN]) {
            playerMovement(&player, 0, DOWN);
        }
        if (currentKeyStates[SDL_SCANCODE_LEFT]) {
            playerMovement(&player, LEFT, 0);
        }
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
            playerMovement(&player, RIGHT, 0);
	}
      
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, Mapping, NULL, NULL);	  
            
      renderText(renderer, score); 	        
      if (checkCollisionEn(&player, &enermy) == 1) {
     	      renderGameOver(renderer);
	      score = 0; 
     	      player.x = WIDTH / 2; 
	      player.y = HEIGHT / 2; 
      }

      if (checkCollisionFood(&player, &food)) {
            RandomFootPos(&food);  
	    score++; 	     
      }
      updatePlayerToEnermy1(&enermy, &player);
      
      SDL_Rect drawPlayer = {player.x, player.y, player.width, player.height};
      SDL_RenderCopy(renderer, Playertexture, NULL, &drawPlayer);

      SDL_Rect drawfood = {food.x, food.y, food.width, food.height};
      SDL_RenderCopy(renderer, foodtexture, NULL, &drawfood); 
     
      SDL_Rect Enermy = {enermy.x, enermy.y, ENERMY_WIDTH, ENERMY_HEIGHT};
      SDL_RenderCopy(renderer, Entexture, NULL, &Enermy); 
     
      SDL_RenderPresent(renderer);
      SDL_Delay(16);
     }
    return 0;
} 
