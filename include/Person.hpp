#ifndef		__H_PERSON__
#define		__H_PERSON__

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Person {
	public:
		Person();
		void initialize();
		int getHealth();
		void setHealth(int health);
		sf::Sprite getSprite();
		void harm(int hp);

		// DEPRECATED, see body of update();
		void updatePosition(int x, int y);

		// Where we do things per frame like updating player movement
		void update();

		// Renders extra stuff we may want to display with the player
		void render(sf::RenderTarget& window);

		// Get the player speed in pixels per second
		float getSpeed();

		// Set the player speed in pixels per second
		void setSpeed(float pixelsPerSecond);
		
	private:
		sf::Sprite sprite;
		sf::Texture texture;
		float x;
		float y;
		float speed;
		int health;
		sf::SoundBuffer punchBuffer;
		sf::Sound punch;

		// Used to calculate the delta time (time between frames) for use in movement
		sf::Clock movementClock;
};

#endif
