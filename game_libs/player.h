// Sanke Logic revap --> ROBOT.BAT VIDEO GAME 
#ifndef PLAYER_H 
#define PLAYER_H

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Player;

void snakeMovement(Player *player, int dx, int dy) {
    player->x += dx;
    player->y += dy;
}

Player Createsnake(int x, int y, int width, int height) {
    Player player = {x, y, width, height};
    return player;
}

#endif 
