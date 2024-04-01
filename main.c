#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> 
#include <time.h>
#include <unistd.h>
#include "renderText.h"
#include "map.h"
#include "player.h"

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


typedef struct {
    int x;
    int y;
    int width;
    int height;
    int speed; 
} Enermy;

Enermy CreateEnermy(int x, int y, int width, int height, int speed) {
    Enermy enermy = {x, y, width, height, speed};
    return enermy;
} 

typedef struct {
    int x;
    int y;
    int width; 
    int height;
} Player;

void playerMovement(Player *player, int dx, int dy) {
    player->x += dx;
    player->y += dy;
}

Player Createplayer(int x, int y, int width, int height) {
    Player player = {x, y, width, height};
    return player;
} 
 
typedef struct {
    int x;
    int y;
    int width; 
    int height;
} Food;

Food CreateFood(int x, int y, int width, int height) { 
    Food food = {x, y, width, height};
    return food;
} 

void RandomFootPos(Food *food) {
     srand(time(0));
     int random_height = (rand() % 450);
     int random_witdht = (rand() % 450);
     food->x = random_witdht;
     food->y = random_height;
} 

// Curlission detection for the GAME // 
bool checkCollision(Player* player, Food* food) {
    return (player->x < food->x + food->width &&
            player->x + player->width > food->x &&
            player->y < food->y + food->height &&
            player->y + player->height > food->y);
}

// Call it an enermy header file 
void updatePlayerToEnermy1(Enermy* enermy, Player* player) {
    int deltaX = player->x - enermy->x;
    int deltaY = player->y - enermy->y;
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    if (distance < DISTANCE_CONSTANT) {
        // Adjust the enemy's position based on the normalized direction
        enermy->x += (player->x - enermy->x) * enermy->speed / distance;
        enermy->y += (player->y - enermy->y) * enermy->speed / distance;
    } else {
        // Reset the enemy's position when the player is far away
        enermy->x = 200;
        enermy->y = 200;
    }
}


//* Okay set food on rendome position and render it on the screen // 
void render2Enermy(SDL_Texture* enermyTexture, SDL_Renderer* renderer) {
      srand(time(0));  
      int random_x = (rand() % 450);  
      int random_y = (rand() % 450);   
      //* Get the value that get updated and pass it in the loop  
      SDL_Rect drawEnermy = {random_x, random_y,  ENERMY_WIDTH, ENERMY_HEIGHT};
      SDL_RenderCopy(renderer,  enermyTexture, NULL, &drawEnermy); 
}


//* This part must be in another header file for renderer // 
int main() {
    printf("Initing the SDL_INTI SYSTEM...\n");
    int score = 0; 
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

    SDL_Surface* enermySurface = SDL_LoadBMP("art/player.bmp"); 
    SDL_Texture* enermyTexture = SDL_CreateTextureFromSurface(renderer, enermySurface);
    if (!enermySurface && !enermyTexture) {
        return -1;
    } 
    SDL_FreeSurface(enermySurface);  

    SDL_Surface* foodSurface = SDL_LoadBMP("art/food.bmp");
    SDL_Texture* foodTexture = SDL_CreateTextureFromSurface(renderer, foodSurface);
    if (!foodSurface && !foodTexture) {
        return -1;
    }
    SDL_FreeSurface(foodSurface);  

          
    Food food = CreateFood(300, 300, 50, 50); 
    Player player = Createplayer(100, 100, 50, 50); 
    Enermy enermy = CreateEnermy(200, 200, 50, 50, 1);  
     
     SDL_Event event;
     while (true) {
	if (SDL_PollEvent(&event) < 0) {
		if (event.type == SDL_QUIT)
			break;
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
        
     if (checkCollision(&player, &food)) 
     {
           RandomFootPos(&food);  
	    score++;
     }
     
     updatePlayerToEnermy1(&enermy, &player);   
     render2Enermy(enermyTexture, renderer);
     
     SDL_RenderClear(renderer);
     SDL_RenderCopy(renderer, Texture(renderer), NULL, NULL);	
      
      renderText(renderer, score); 
      
      SDL_Rect drawPlayer = {player.x, player.y, player.width, player.height};
      SDL_RenderCopy(renderer, PlayerTexture(renderer), NULL, &drawPlayer);

      SDL_Rect drawfood = {food.x, food.y, food.width, food.height};
      SDL_RenderCopy(renderer, foodTexture, NULL, &drawfood); 
      
      SDL_RenderPresent(renderer);
      SDL_Delay(16);
     }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
   
    return 0;
} 
