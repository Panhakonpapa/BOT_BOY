#ifndef MATH_H
#define MATH_H 
#include <cmath> 
class Enermy {
	private:  
		int enx; 
		int eny; 
		int width;
		int height;
		int speed = 10; 
		float CONSTANT = 200;
	public:	
		void set_Pos(int set_x, int set_y) {	
			enx = set_x; 
			eny = set_y; 			
		}
		int get_POSX() {
			return enx;
		}
		
		int get_POSY() {
			return eny;
		}
		
		std::pair<int, int> Movement(int plx, int ply) {
			int daltaX = plx - enx;
			int daltaY = ply - eny; 
			float distance = sqrt(daltaX * daltaX + daltaY * daltaY);
			if (distance < CONSTANT) {
				int newEnx = enx + (plx - enx) * speed / distance; 
				int newEny = eny + (ply - eny) * speed / distance; 
				return std::make_pair(newEnx, newEny);	
			}
			else {	
				return std::make_pair(enx, eny);	
			}

		}   
		//void Expolode() {	
		//}   
	
};
#endif
