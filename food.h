#ifndef FOOD_H 
#define FOOD_H 
#include <stdio.h> 
typedef struct {
    int x;
    int y;
    int width; 
    int height;
} Food;
Food CreateFood(int x, int y, int width, int height); 
#endif 

