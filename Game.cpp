/*
 * Game.cpp
 * Much code taken from SFML tutorials on SFML site.  Basic 
 * flow tutorial at 
 * from https://maksimdan.gitbooks.io/sfml-and-gamedevelopement/content/game_class.html
 *
 */

#include "Game.hpp"
#include "Person.hpp"
#include "Monster.hpp"
#include <iostream>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

Game::Game(){
	window.create(sf::VideoMode(800, 600), "Not on my block.");
	done = false;
	monsters.push_back(Monster());
}

int Game::start(){
	sf::Texture splash;
	if(!splash.loadFromFile("./images/neighborhood.png")){
		return EXIT_FAILURE;
	}
	sf::Sprite sprite;
	sprite.setTexture(splash);

	sf::Font font;
	if(!font.loadFromFile("fonts/Notable-Regular.ttf")){
		return EXIT_FAILURE;
	}

	sf::Text title;
	title.setFont(font);
	title.setString("Not on my block.");
	title.setCharacterSize(64);
	title.setFillColor(sf::Color::White);
	title.setPosition(10,200);

	sf::Text text;
	text.setFont(font);
	text.setString("(Press Enter to continue)");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(150, 350); 

	sf::Clock clock;

	sf::SoundBuffer buffer;
	if(!buffer.loadFromFile("music/epic_hero.wav")){
		return EXIT_FAILURE;
	}

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
			}

			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Return){
					window.clear();
					return 0;
				}
			}

		}

		window.clear();
		window.draw(sprite);
		window.draw(title);
		window.draw(text);
		window.display();

		sf::Time time = clock.getElapsedTime();
		sf::Int32 mills = time.asMilliseconds();
		if(mills % 1000 > 500){
			text.setFillColor(sf::Color::Black);
		} else {
			text.setFillColor(sf::Color::White);
		}
	}

	return 0;
}

int Game::run()
{
	sf::SoundBuffer buffer;
	if(!buffer.loadFromFile("music/in_game.wav")){
		std::cerr << "Unable to load in_game music file." << std::endl;
		return EXIT_FAILURE;
	}

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

	while (window.isOpen())
	{
		processEvents();
		update();
		render();
	}
	return EXIT_SUCCESS;
}

void Game::processEvents()
{
	sf::Event event;
	while (!done && window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				switch(event.key.code){
					std::cout << event.key.code;
					case sf::Keyboard::Left:
						player.updatePosition(-20, 0);
						break;
					case sf::Keyboard::Right:
						player.updatePosition(20, 0);
						break;
					case sf::Keyboard::Up:
						player.updatePosition(0, -20);
						break;
					case sf::Keyboard::Down:
						player.updatePosition(0, 20);
						break;
					default:
						break;
				}				
			default:
				break;
		}
	}
}

void Game::update()
{
	if(player.getHealth() < 0){
		done = true;
	}
}

void Game::render()
{
	window.clear();
	window.draw(player.getSprite());
	for(auto it = monsters.begin(); it != monsters.end(); ++it){
		window.draw( it->getSprite() );
	}
	window.display();
}
