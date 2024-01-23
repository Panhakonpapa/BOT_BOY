#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define WIDTH 800
#define HEIGHT 600
#define WIDTH_SNAKE 50
#define HEIGHT_SNAKE 50
#define DELAY 400
#define RIGHT 10 
#define LEFT -10
#define UP 10 
#define DOWN -10 
SDL_Window *window;
SDL_Renderer *renderer;

// Memeroy OF Snake // 
//
typedef struct {
    int x;
    int y;
    int width;
    int height;
} Snake;

// Memeroy of FOOD // 
//
typedef struct {
    int x;
    int y;
    int width;
    int height;
} Food;

// Snake Movement 
//
void snakeMovement(Snake *snake, int dx, int dy) {
    snake->x += dx;
    snake->y += dy;
}
// Fuction that Make Food 
//
Food CreateFood(int x, int y, int width, int height) { 
    Food food = {x, y, width, height};
    return food;
}
// Fuction that Make Snake
//
Snake Createsnake(int x, int y, int width, int height) {
    Snake snake = {x, y, width, height};
    return snake;
} 

// Curlission detection for the GAME // 
//
bool checkCollision(Snake* snake, Food* food) {
    return (snake->x < food->x + food->width &&
            snake->x + snake->width > food->x &&
            snake->y < food->y + food->height &&
            snake->y + snake->height > food->y);
}

int main() {
    printf("Initing the SDL_INTI SYSTEM...\n");

    SDL_Init(SDL_INIT_EVERYTHING);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
	printf("Someting went wrong with SDL_INIT...\n");
    }

    window = SDL_CreateWindow(
	"VIDEO GAME",
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
    
//   RENDERING PIXEL SPRITE HERE  
    
    // MAP BACKGROUND //
    SDL_Surface* spriteSurface = SDL_LoadBMP("art/map.bmp");
    if (!spriteSurface) {
        return -1;
    }
    SDL_Texture* spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteSurface);
    SDL_FreeSurface(spriteSurface);
    if (!spriteTexture) { 
        return -1;  
    }


    // PLAYER GAME BOY // 
    SDL_Surface* snakeSurface = SDL_LoadBMP("art/blop.bmp");
    if (!snakeSurface) {
        return -1;
    }
    SDL_Texture* snakeTexture = SDL_CreateTextureFromSurface(renderer, snakeSurface);
    SDL_FreeSurface(snakeSurface); 
    if (!snakeTexture) {
        return -1;
     }


    // ENERMY BOOM // 
    SDL_Surface* bombSurface = SDL_LoadBMP("art/player.bmp");
    if (!bombSurface) {
        return -1;
    }
    SDL_Texture* bombTexture = SDL_CreateTextureFromSurface(renderer, bombSurface);
    SDL_FreeSurface(bombSurface);  
    if (!bombTexture) {
        return -1;
     }

    SDL_Surface* foodSurface = SDL_LoadBMP("art/food.bmp");
    if (!foodSurface) {
        return -1;
    }
    SDL_Texture* foodTexture = SDL_CreateTextureFromSurface(renderer, foodSurface);
    SDL_FreeSurface(foodSurface);  
    if (!foodTexture) {
        return -1;
     }






     // INIT the OBJECT SYSTEM OF THE GAME // 
     Food food = CreateFood(300, 300, 50, 50); 
     Snake snake = Createsnake(100, 100, 50, 50); 
     Snake bomb = Createsnake(200, 200, 50, 50);
    



     // Game Event loop Hendling // 
     SDL_Event event;
     while (true) {
        // Main event Hendling Here // 	
	if (SDL_PollEvent(&event) < 0) {
		if (event.type == SDL_QUIT)
			break;
	}	
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if (currentKeyStates[SDL_SCANCODE_UP]) {
            snakeMovement(&snake, 0, -10);
        }
        if (currentKeyStates[SDL_SCANCODE_DOWN]) {
            snakeMovement(&snake, 0, 10);
        }
        if (currentKeyStates[SDL_SCANCODE_LEFT]) {
            snakeMovement(&snake, -10, 0);
        }
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
            snakeMovement(&snake, 10, 0);
        }
        
        if (checkCollision(&snake, &food)) {
        // Handle collision, e.g., stop player movement or deduct health
        printf("Collision detected!\n");
    }
      // Clear the renderer
      //
      SDL_RenderClear(renderer);

      // Render the background
      //
      SDL_RenderCopy(renderer, spriteTexture, NULL, NULL);

      // Render the snake
      //
      SDL_Rect drawSnake = {snake.x, snake.y, snake.width, snake.height};
      SDL_RenderCopy(renderer, snakeTexture, NULL, &drawSnake);

      // Render the Bomb
      //
      SDL_Rect drawbomb = {bomb.x, bomb.y, bomb.width, bomb.height};
      SDL_RenderCopy(renderer, bombTexture, NULL, &drawbomb);
      
      // Render the Food
      //
      SDL_Rect drawfood = {food.x, food.y, food.width, food.height};
      SDL_RenderCopy(renderer, foodTexture, NULL, &drawfood);

      // Present the renderer
      //
      SDL_RenderPresent(renderer);
      SDL_Delay(16);
     }


    SDL_DestroyTexture(spriteTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
   return 0;
} 
