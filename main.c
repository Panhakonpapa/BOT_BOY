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
typedef struct {
    int x;
    int y;
    int width;
    int height;
} Snake;
void snakeMovement(Snake *snake, int dx, int dy) {
    snake->x += dx;
    snake->y += dy;
}

Snake Createsnake(int x, int y, int width, int height) {
    Snake snake = {x, y, width, height};
    return snake;
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
    SDL_Surface* spriteSurface = SDL_LoadBMP("art/map.bmp");
    if (!spriteSurface) {
        // Handle sprite loading error
        return -1;
    }

    SDL_Texture* spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteSurface);
    SDL_FreeSurface(spriteSurface);  // Free the surface, as it's no longer needed

    if (!spriteTexture) {
        // Handle texture creation error
        return -1;  
    }


    SDL_Surface* snakeSurface = SDL_LoadBMP("art/player.bmp");
    if (!snakeSurface) {
        // Handle snake loading error
        return -1;
    }

    SDL_Texture* snakeTexture = SDL_CreateTextureFromSurface(renderer, snakeSurface);
    SDL_FreeSurface(snakeSurface);  // Free the surface, as it's no longer needed

    if (!snakeTexture) {
        // Handle texture creation error
        return -1;
    }
     Snake snake = Createsnake(100, 100, 50, 50);
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

      // Clear the renderer
      SDL_RenderClear(renderer);

      // Render the background
      SDL_RenderCopy(renderer, spriteTexture, NULL, NULL);

      // Render the snake
      SDL_Rect drawSnake = {snake.x, snake.y, snake.width, snake.height};
      SDL_RenderCopy(renderer, snakeTexture, NULL, &drawSnake);

      // Present the renderer
      SDL_RenderPresent(renderer);
      SDL_Delay(16);
     }
    SDL_DestroyTexture(spriteTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
   return 0;
} 
