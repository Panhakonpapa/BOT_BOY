#ifdef ENERMY_H
#define ENERMY_H
typedef struct {
    int x;
    int y;
    int width;
    int height;
    int speed; 
} Enermy;


Enermy CreateEnermy(int x, int y, int width, int height, int speed) {
    Enermy enermy = {x, y, width, height, speed};
    return enermy;
}


Enermy enermy = CreateEnermy(200, 200, 50, 50, 5); 

#endif 
