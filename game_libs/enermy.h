#ifndef ENERMY_H
#define ENERMY_H
Enermy CreateEnermy(int x, int y, int width, int height, int speed) {
    Enermy enermy = {x, y, width, height, speed};
    return enermy;
}
#endif 
