
// THe goal for today  
// get the enermy working 
// clean up the code i write 
// clean up stuff like varible 
// fix some bug 
// cleaan game  libary 
// creatring better docimentation 
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> 
#include <time.h>
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
//typedef struct {
//    int x;
//    int y;
//    int width;
//    int height;
// } Enermy;

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
    int width; int height;
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
//
bool checkCollision(Player* player, Food* food) {
    return (player->x < food->x + food->width &&
            player->x + player->width > food->x &&
            player->y < food->y + food->height &&
            player->y + player->height > food->y);
}


// Adding AI to may Game project:) 

void updatePlayerToEnermy(Enermy* enermy, Player* player) {
	int DaltaX = player->x - enermy->x; 
	int DaltaY = plyaer->y - enermy-y;
	float distence = sqrt((DaltaX * DaltaX) - (DaltaY * DaltaY)); 

	if (distence < DISTENC_CONSTANE) {
		enermy-x = (player->x - enermy->x) * enermy->speed / distence; 
		enermy-x = (player->y - enermy->y) * enermy->speed / distence; 
	}
	else {
    		enermy-x = 100; 
		enermy->y = 100; 
	}
}




int main() {
    
    int battery = 0;  
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
    SDL_Surface* playerSurface = SDL_LoadBMP("art/blop.bmp");
    if (!playerSurface) {
        return -1;
    }
    SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(renderer,  playerSurface);
    SDL_FreeSurface(playerSurface); 
    if (!playerTexture) {
        return -1;
     }
// I use neovim btw

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
     Player player = Createplayer(100, 100, 50, 50); 
     Player bomb = Createplayer(200, 200, 50, 50);
    
      // Clear the renderer
      //
      SDL_RenderClear(renderer);

      // Render the background
      //
      SDL_RenderCopy(renderer, spriteTexture, NULL, NULL);

      // Render the snake
      //
      SDL_Rect drawPlayer = {player.x, player.y, player.width, player.height};
      SDL_RenderCopy(renderer, playerTexture, NULL, &drawPlayer); 
      SDL_RenderPresent(renderer);
      // Rendering Food object  
      //
      SDL_Rect drawfood = {food.x, food.y, food.width, food.height};
      SDL_RenderCopy(renderer, foodTexture, NULL, &drawfood); 
      SDL_RenderPresent(renderer);
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
            playerMovement(&player, 0, -30);
        }
        if (currentKeyStates[SDL_SCANCODE_DOWN]) {
            playerMovement(&player, 0, 30);
        }
        if (currentKeyStates[SDL_SCANCODE_LEFT]) {
            playerMovement(&player, -30, 0);
        }
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
            playerMovement(&player, 30, 0);
        }
        
        if (checkCollision(&player, &food)) {
        // Handle collision, e.g., stop player movement or deduct health	
        RandomFootPos(&food);  
	battery += 100;  
	printf("Batter life --> %d\n", battery);
    }
      // Clear the renderer
      //
      SDL_RenderClear(renderer);

      // Render the background
      //
      SDL_RenderCopy(renderer, spriteTexture, NULL, NULL);

      // Render the snake
      //
      SDL_Rect drawPlayer = {player.x, player.y, player.width, player.height};
      SDL_RenderCopy(renderer, playerTexture, NULL, &drawPlayer);

      // Render the Bomb
      //
      SDL_Rect drawbomb = {bomb.x, bomb.y, bomb.width, bomb.height};
      SDL_RenderCopy(renderer, bombTexture, NULL, &drawbomb);
     
      // Render a snake 
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
