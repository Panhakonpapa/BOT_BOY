#include <iostream> 
#include <cmath> 
#include "player.h"
#include <cstdlib> 
#include <utility>

int main() {
	Player Bot;
	int x; 
	int y;
	int width; 
	int height;
	
	Bot.createPlayer(100, 100, 50, 50);
	x = Bot.get_POSX();
	y = Bot.get_POSY();
	height = Bot.Height();
	width = Bot.Width();


	std::cout << " " << x << std::endl;
	std::cout << " " << y << std::endl;	
	std::cout << " " << width << std::endl;
	std::cout << " " << height << std::endl;
	return 0;
}
