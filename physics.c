#include "physics.h"
#include "food.h" 
#include "player.h" 
#define DISTANCE_CONSTANT 800 
void RandomFootPos(Food *food) {
     srand(time(0));
     int random_height = (rand() % 450);
     int random_witdht = (rand() % 450);
     food->x = random_witdht;
     food->y = random_height;
} 

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
        enermy->x += (player->x - enermy->x) * enermy->speed / distance;
        enermy->y += (player->y - enermy->y) * enermy->speed / distance;
    } else {
        enermy->x = 200;
        enermy->y = 200;
    }
}

