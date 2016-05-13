#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Character.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	window.setFramerateLimit(60);

	sf::Texture texture;
	if (!texture.loadFromFile("Textures/woodfloor_c.png"))
		printf("Failure to load file\n");
	texture.setRepeated(true);

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect({ 0,0,800,800 });

	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("Textures/Player.png"))
		printf("Failure to load file\n");

	sf::Sprite playerSprite;
	playerSprite.setTexture(playerTexture);
	playerSprite.setScale(0.5,0.5);

	sf::Texture enemyTexture;
	if (!enemyTexture.loadFromFile("Textures/Enemy.png"))
		printf("Failure to load file.\n");

	sf::Sprite enemySprite;
	enemySprite.setTexture(enemyTexture);
	enemySprite.setScale(0.5, 0.5);
	srand(time(NULL));
	enemySprite.setPosition(rand()%750, rand()%750);


	Character charc;







	//Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			playerSprite.setPosition(playerSprite.getPosition().x + 5, playerSprite.getPosition().y);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y + 5);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y - 5);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			playerSprite.setPosition(playerSprite.getPosition().x - 5, playerSprite.getPosition().y);

		window.clear();
		window.draw(shape);
		window.draw(sprite);
		window.draw(playerSprite);
		window.draw(enemySprite);
		window.display();
	}

	return 0;
}