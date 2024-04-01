#include "renderText.h" 
const char* fontPath = "/home/panha/sanke/Snake_Game/art/ErbosDraco1StNbpRegular-99V5.ttf";
TTF_Font* font; 
SDL_Surface* textSurface = NULL; 
SDL_Texture* textTexture = NULL; 

void openFont(const char* fontPath) {
	font = TTF_OpenFont(fontPath, 23);	 
	if (!font) {
		perror("error font can't open\n");
	}
}
void init_texture() {
	if (TTF_Init() < 0) {
        fprintf(stderr, "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);  
	}
}

void renderText(SDL_Renderer* renderer, int score) {
      init_texture();
      openFont(fontPath);
      char scoreText[20]; sprintf(scoreText, "%d", score);
      //* set color for texture // 
      SDL_Color bgColor = {0, 0, 0, 255};     
      SDL_Color fgColor = {255, 255, 255, 255};   
      
      //* surface the texture // 
      textSurface = TTF_RenderText_Shaded(font, scoreText, bgColor, fgColor);
      textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);   
      
      //* Get it possition on the screen  
      int textX = (800 - textSurface->w) / 2;
      int textY = 10; 

      //* Copy into the main window buffer  
      SDL_Rect textRect = {textX, textY, 100, 50};  
      SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
} 

