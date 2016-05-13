#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Character.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Game Engine Window");
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

	Player player;
	
	sf::Texture enemyTexture;
	if (!enemyTexture.loadFromFile("Textures/Enemy.png"))
		printf("Failure to load file.\n");

	sf::Sprite enemySprite;
	enemySprite.setTexture(enemyTexture);
	enemySprite.setScale(0.5, 0.5);
	srand(time(NULL));

	Enemy enemy;
	enemy.setX(rand() % 750);
	enemy.setY(rand() % 750);

	//Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player.playerInput();
		printf("X:%i Y:%i\n", player.getX(), player.getY());
		playerSprite.setPosition(player.getX(), player.getY());

		enemySprite.setPosition(enemy.getX(), enemy.getY());

		window.clear();
		window.draw(sprite);
		window.draw(playerSprite);
		window.draw(enemySprite);
		window.display();
	}

	return 0;
}