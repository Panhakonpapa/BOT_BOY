// Sanke Logic revap --> ROBOT.BAT VIDEO GAME 
#ifndef PLAYER_H 
#define PLAYER_H
class Player {
	private: 
		int POSX;
		int POSY;
		int width;
		int height;
	public: 
		void createPlayer(int set_x, int set_y, int set_width, int set_height) {	
			POSX = set_x;
			POSY = set_y;
			width = set_width;
			height = set_height;	
		}	
		void snakeMovement(int dx, int dy) {
			POSX += dx;
			POSY += dy;
		}
		int get_POSX() {
			return POSX;
		}	
		int get_POSY() {
			return POSY;
		}
		int Height() {
			return height;
		}
		int Width() {
			return width;
		}

};

#endif
