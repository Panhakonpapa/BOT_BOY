#include "renderText.h" 
TTF_Font* font = NULL;
SDL_Surface* textSurface = NULL;
SDL_Texture* textTexture = NULL; 	 		     	 	 
void openFont(const char* filePath) {	
       font = TTF_OpenFont(filePath, 23);	 
      	if (!font) {
		printf("Font error kill yourself\n"); 	
       } 
}

void renderText(SDL_Renderer* renderer, int score) { 
      char scoreText[20]; sprintf(scoreText, "%d", score);
      SDL_Color bgColor = {0, 0, 0, 255};     
      SDL_Color fgColor = {255, 255, 255, 255};   
      textSurface = TTF_RenderText_Shaded(font, scoreText, bgColor, fgColor);		 
      textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);   	 
      SDL_FreeSurface(textSurface);
      int textX = (800 - textSurface->w) / 2;
      int textY = 10; 
      SDL_Rect textRect = {textX, textY, 100, 50};  
      SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
      TTF_CloseFont(font);
}


