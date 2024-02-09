#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> 
#include <time.h>
#include <unistd.h>
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
TTF_Font* font; // Font for rendering text

// Memeroy OF Snake // 
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

void updatePlayerToVIM(Enermy* VIM, Player* player) {
    int deltaX = player->x - VIM->x;
    int deltaY = player->y - VIM->y;
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    if (distance < DISTANCE_CONSTANT) {
        // Adjust the enemy's position based on the normalized direction
        VIM->x += (player->x - VIM->x) * VIM->speed / distance;
        VIM->y += (player->y - VIM->y) * VIM->speed / distance;
    } else {
        // Reset the enemy's position when the player is far away
        VIM->x = 450;
        VIM->y = 450;
    }
}
void render2Enermy(SDL_Texture* enermyTexture, SDL_Renderer* renderer) {
      srand(time(0));  
      int random_x; 
      int random_y; 
      random_x = (rand() % 450);  
      random_y = (rand() % 450);  
      SDL_Rect drawEnermy = {random_x, random_y,  ENERMY_WIDTH, ENERMY_HEIGHT};
      SDL_RenderCopy(renderer,  enermyTexture, NULL, &drawEnermy); 
}
void render3Enermy(SDL_Texture* enermyBBBTexture, SDL_Renderer* renderer, Enermy* VIM) {
	SDL_Rect drawEnermy = {VIM->x, VIM->y, VIM->width, VIM->height}; 
	SDL_RenderCopy(renderer,  enermyBBBTexture, NULL, &drawEnermy); 
}
int main() {
    printf("Initing the SDL_INTI SYSTEM...\n");
    int score = 0; 
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
	printf("Someting went wrong with SDL_INIT...\n"); 
        exit(EXIT_FAILURE);  // Exit the program or handle the error accordingly
    }
    
    if (TTF_Init() < 0) {
        fprintf(stderr, "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);  // Exit the program or handle the error accordingly
    }
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);  // Exit the program or handle the error accordingly
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

     const char* fontPath = "/home/panha/sanke/Snake_Game/art/ErbosDraco1StNbpRegular-99V5.ttf";
     font = TTF_OpenFont(fontPath, 23);
     if (!font) {
             fprintf(stderr, "Unable to load font! SDL_ttf Error: %s\n", TTF_GetError());
    	     printf("Exit_FALURE\n");  
	     return -1;  
      } 

//   RENDERING PIXEL SPRITE HERE  
    
    // MAP BACKGROUND //
    SDL_Surface* spriteSurface = SDL_LoadBMP("art/mapRobo.bmp");
    if (!spriteSurface) {
        return -1;
    }
    SDL_Texture* spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteSurface);
    SDL_FreeSurface(spriteSurface);
    if (!spriteTexture) { 
        return -1;  
    }
    printf("Loading Bitmap Background success :)...\n"); 

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
    printf("Loading Bitmap Player success :)...\n"); 

    // ENERMY BOOM // 
    SDL_Surface* enermySurface = SDL_LoadBMP("art/player.bmp");
    if (!enermySurface) {
        return -1;
    } 
    SDL_Texture* enermyTexture = SDL_CreateTextureFromSurface(renderer, enermySurface);
    SDL_FreeSurface(enermySurface);  
    if (!enermyTexture) {
        return -1;
     }


    SDL_Surface* enermySur = SDL_LoadBMP("art/blop.bmp");
    if (!enermySur) {
        return -1;
    } 
    SDL_Texture* enermyBBBTexture = SDL_CreateTextureFromSurface(renderer, enermySur);
    SDL_FreeSurface(enermySur);  
    if (!enermyBBBTexture) {
        return -1;
     }
    printf("Loading Bitmap Enermy success :)...\n");  
    // FOOD FOR GAME // 
    SDL_Surface* foodSurface = SDL_LoadBMP("art/food.bmp");
    if (!foodSurface) {
        return -1;
    }
    SDL_Texture* foodTexture = SDL_CreateTextureFromSurface(renderer, foodSurface);
    SDL_FreeSurface(foodSurface);  
    if (!foodTexture) {
        return -1;
     }
    printf("Loading Bitmap Food success :)...\n"); 


    SDL_Surface* textSurface = NULL;
    SDL_Texture* textTexture = NULL;
    printf("INIT_TEXTUE_FONT\n");


    // INIT the OBJECT SYSTEM OF THE GAME // 
     Food food = CreateFood(300, 300, 50, 50); 
     Player player = Createplayer(100, 100, 50, 50); 
     Enermy enermy1 = CreateEnermy(200, 200, 50, 50, 1);  
     Enermy VIM = CreateEnermy(400, 400, 50, 50, 1); 
     // Clear the renderer
      SDL_RenderClear(renderer);

      // Render the background
      SDL_RenderCopy(renderer, spriteTexture, NULL, NULL);

      // Render the snake
      SDL_Rect drawPlayer = {player.x, player.y, player.width, player.height};
      SDL_RenderCopy(renderer, playerTexture, NULL, &drawPlayer); 
      SDL_RenderPresent(renderer);
      
      // Rendering Food object  
      SDL_Rect drawfood = {food.x, food.y, food.width, food.height};
      SDL_RenderCopy(renderer, foodTexture, NULL, &drawfood); 
      SDL_RenderPresent(renderer);
      printf("Entering Main()\n"); 
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
        
        if (checkCollision(&player, &food)) {
           // Handle collision, e.g., stop player movement or deduct health	
           RandomFootPos(&food);  
           // Score on the window 
	    score++;
     }
     updatePlayerToEnermy1(&enermy1, &player);  
     // Clear the renderer
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, spriteTexture, NULL, NULL);


      char scoreText[20];
      sprintf(scoreText, "%d", score);
      SDL_Color bgColor = {0, 0, 0, 255};  // Black background color   
      SDL_Color fgColor = {255, 255, 255, 255};  // White foreground color   
      textSurface = TTF_RenderText_Shaded(font, scoreText, bgColor, fgColor);
      textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);   
      int textX = (WIDTH - textSurface->w) / 2;
      int textY = 10;   
      SDL_Rect textRect = {textX, textY, 100, 50};  
      SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
     


      // Render my GAMEBOY
      SDL_Rect drawPlayer = {player.x, player.y, player.width, player.height};
      SDL_RenderCopy(renderer, playerTexture, NULL, &drawPlayer);

      // Render the Bomb
      updatePlayerToEnermy1(&enermy1, &player);  
      SDL_Rect drawEnermy1 = {enermy1.x, enermy1.y, enermy1.width, enermy1.height};
      SDL_RenderCopy(renderer,  enermyTexture , NULL, &drawEnermy1);	      
      
      updatePlayerToVIM(&VIM, &player);  
      render3Enermy(enermyBBBTexture, renderer, &VIM); 


      render2Enermy(enermyTexture, renderer);
      // Render a food
      SDL_Rect drawfood = {food.x, food.y, food.width, food.height};
      SDL_RenderCopy(renderer, foodTexture, NULL, &drawfood); 
      // Present the renderer
      //
      SDL_RenderPresent(renderer);
      SDL_Delay(16);
     }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyTexture(spriteTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
   
    return 0;
} 
