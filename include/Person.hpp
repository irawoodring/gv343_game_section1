#ifndef		__H_PERSON__
#define		__H_PERSON__

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

enum PlayerDirection {
	East,
	West,
};

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

        bool running = true;

		// Used to calculate the delta time (time between frames) for use in movement
		sf::Clock movementClock;

        // Used to animate the player over time
        sf::Clock animationClock;

		// The frame size of each player sprite in the bigger texture
        sf::IntRect playerFrameSize = sf::IntRect(0, 0, 16, 32);

		// Which animation frame we are currently on
        unsigned int currentFrame = 0;

		// Which direction the player is currently facing
		PlayerDirection facing = PlayerDirection::East;

		// The frames to cycle during the idle animation
        std::array<unsigned, 3> idleAnim = { 0, 1, 2 };

		// The frames to cycle during the run animation
        std::array<unsigned, 6> runAnim = { 3, 4, 5, 6, 7, 8 };
};

#endif
