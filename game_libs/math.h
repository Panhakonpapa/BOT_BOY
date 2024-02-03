#ifndef MATH_H
#define MATH_H 

#include <math.h> 
#define DISTANCE_CONSTANT 100.0f
typedef struct {
    int x;
    int y;
    int width;
    int height;
} Player;


typedef struct {
    int x;
    int y;
    int width;
    int height;
    int speed; 
} Enermy;

void updatePlayerToEnermy(Enermy* enermy, Player* player) {
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
#endif 
