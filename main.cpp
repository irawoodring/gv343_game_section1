#include <iostream>
#include "SFML/Graphics.hpp"
#include "Intro.hpp"
#include "Game.hpp"

int main(int argc, char** argv){
	Game g;
	while(true){
		int started = g.start();
    if (started  < 0) {
      std::cerr << "Error! Game failed to start" << std::endl;
      break;
    }
		g.run();
	}
}
