//* Snaking Moudle for [bloppy] // 
#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
//* Defining Macro // 
//
#define HEIGHT 20
#define WIDTH 20
//* Trail for link list 
//
struct Tail {
   int x, y; 
}
//* Poke Snake into memory // 
struct Snake {
     int x; 
     int y; 
     int direction; 
     int HEIGHT; 
     int WIDTH; 
     int size;
     struct Tail *tail; 
}
// Interllizing Snake [Bloppy] 
//
void snakeSetup(struct Snake *snake, struct Food *food) {
	snake->x = 100; 
	snake->y = 100;
	snake->direction = 0; 
	snake->HEIGHT = HEIGHT; 
	snake->WIDTH = WIDTH; 
	snake->size = 0; 
	snake->tail = malloc(sizeof(struct Tail)); 
}
// Snake wall colition deticion 
//
int snakeHitwall(struct Snake *snake) {
     if (snake->x < 0 || snake->y < 0) {
             return 0; 
     }
     if (snake->x > 490 || snake->y > 490) {
             return 0; 
     }
     return 1; 
}
#endif //SNAKE_SNAKE_H
