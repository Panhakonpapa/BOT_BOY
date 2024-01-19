//           Libary for rendering food // 19/Jan/2024/ // no use case // for my game//   
//
#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H
// Poking into memory of our snake
//
struct Food {
   int x;
   int y;
}
// Update and rendering our food object
//
void updateFood(struct Food *food, SDL_Renderer *renderer) {
      SDL_Rect rect = {food->x, food->y, 20, 20};
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      SDL_RenderFillRect(renderer, &rect);
      SDL_RenderDrawRect(rendeerer, &rect);
}
// Generate a food or seed for our snake game
//
int RandomFootPos(struct Food *food) {
     srand(time(0));
     int random_height = (rand() % 500);
     int random_witdht = (rand() % 500);
     food->x = random_witdht;
     food->y = random_height;
}





#endif //SNAKE_FOOD_H
