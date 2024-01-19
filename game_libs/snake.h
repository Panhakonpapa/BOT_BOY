//   lIbary for rendering snake on the screen // libary for use in main only // 19/Jan/2024 //  
//
//* Snaking Moudle for [bloppy] // 
#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
//* Defining Macro // 
//
#define HEIGHT 20
#define WIDTH 20
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
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


// Snaking updating using for loop to poke number into memeroy
//
void snakeUpdate(SDL_Render *renderer, struct Snake *snake) {
     SDL_Rect new_t = {snake->tail.x, snake->tail.y, snake->WIDTH, snake->HEIGHT}; 
     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
     SDL_RenderFillRect(renderer, &new_t);
     SDL_RenderDrawRect(renderer, &new_t);
     for (int i = 0; i <= size - 1; i++) {
         SDL_Rect new_t = {snake->tail[i].x, snake->tail[i].y, snake->WIDTH, snake->HEIGHT}; 
         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
         SDL_RenderFillRect(renderer, &new_t);
         SDL_RenderDrawRect(renderer, &new_t);
     } 
}
// Snake-Dead 
//
void snakeDeath(struct Snake * snake, struct Food *food){
    if(!snakeHitwall((snake)){
        free(snake->tail);
        setup(snake, food);
        printf("DEAD\n");
    }
    for(int i = 0; i <= snake->size -1 ; i++){
        int dist = distance(snake->x, snake->y, snake->tail[i].x, snake->tail[i].y);
        if(dist < 1){
            free(snake->tail);
            setup(snake, food);
            printf("DEAD\n");
        }
    }
}

 
#endif //SNAKE_SNAKE_H
