#include "gameover.h" 
TTF_Font* font; 
SDL_Surface* textSurface = NULL; 
SDL_Texture* textTexture = NULL; 

void openFont2(const char* fontPath) {
	font = TTF_OpenFont(fontPath, 23);	 
	if (!font) {
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
     char* scoreText = "GameOver"; 
      //* set color for texture // 
      SDL_Color bgColor = {0, 0, 0, 255};     
      SDL_Color fgColor = {0, 255, 0, 255};   
      
      //* surface the texture // 
      textSurface = TTF_RenderText_Shaded(font, scoreText, bgColor, fgColor);
      textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);  

      //* Get it possition on the screen  
      int textX = 300;
      int textY = 400; 

      //* Copy into the main window buffer  
      SDL_Rect textRect = {textX, textY, 200, 150};  
      SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
} 

