// Sanke Logic revap --> ROBOT.BAT VIDEO GAME 
typedef struct {
    int x;
    int y;
    int width;
    int height;
} Snake;

void snakeMovement(Snake *snake, int dx, int dy) {
    snake->x += dx;
    snake->y += dy;
}
Snake Createsnake(int x, int y, int width, int height) {
    Snake snake = {x, y, width, height};
    return snake;
}

bool checkCollision(Snake* snake, Food* food) {
    return (snake->x < food->x + food->width &&
            snake->x + snake->width > food->x &&
            snake->y < food->y + food->height &&
            snake->y + snake->height > food->y);
}
