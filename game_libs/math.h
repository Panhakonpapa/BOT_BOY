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
