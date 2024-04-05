#ifndef PHYSICS_H 
#define PHYSICS_H
#include <stdbool.h>
#include <math.h> 
#include <time.h>
#include <unistd.h>
#include "player.h"
#include "Enermy.h"
#include "food.h" 
void RandomFootPos(Food *food); 
bool checkCollisionFood(Player* player, Food* food); 
bool checkCollisionEn(Player* player, Enermy* enermy); 
void updatePlayerToEnermy1(Enermy* enermy, Player* player);
#endif 
