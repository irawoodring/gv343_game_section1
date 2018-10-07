#include "SFML/Graphics.hpp"
#include "Game.hpp"
#include "HighScores.hpp"

int main(int argc, char** argv){
	Game g;
	while(true){
		g.start();
		g.run();
	}
}
