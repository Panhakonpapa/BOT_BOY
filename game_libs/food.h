//           Libary for rendering food // 19/Jan/2024/ // no use case // for my game//   
#ifdef FOOD_H
#define FOOD_H
Food CreateFood(int x, int y, int width, int heigth) {
	Food food = {x, y, width, height};
	return food;  
}

void RandomFootPos(Food *food) {
	srand(time(NULL)); 
	int random_x = (rand() % 450); 
	int random_y = (rand() % 450); 
	food->x = random_x; 
	food->y = random_x; 
}
// Curlission detection for the GAME //
bool checkCollision(Player* player, Food* food) {
    return (player->x < food->x + food->width &&
            player->x + player->width > food->x &&
            player->y < food->y + food->height &&
            player->y + player->height > food->y);
}
#endif 
