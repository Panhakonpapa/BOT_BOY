#include "gameover.h" 

#define WIDTH 800 
#define HEIGHT 600 
TTF_Font* font2; 
SDL_Surface* textSurface2 = NULL; 
SDL_Texture* textTexture2 = NULL; 

void openFont2(const char* fontPath) {
	font2 = TTF_OpenFont(fontPath, 23);	 
	if (!font2) {
		perror("error font can't open\n");
	}
}
void init_texture2() {
	if (TTF_Init() < 0) {
        fprintf(stderr, "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);  
	}
}

void renderGameOver(SDL_Renderer* renderer) {
      char* over = "G a m e O v e r"; //* set color for texture // 
      SDL_Color bgColor2 = {0, 0, 0, 255};     
      SDL_Color fgColor2 = {255, 0, 0, 255};   
 
      //* surface the texture // 
      textSurface2 = TTF_RenderText_Shaded(font2, over, bgColor2, fgColor2);
      textTexture2 = SDL_CreateTextureFromSurface(renderer, textSurface2);  

      //* Get it possition on the screen  
      int textX2 = 150;
      int textY2 = 150; 

      //* Copy into the main window buffer  
      SDL_Rect textRect2 = {textX2, textY2, WIDTH / 2, HEIGHT / 2};  
      SDL_RenderCopy(renderer, textTexture2, NULL, &textRect2);
} 

