#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "Character.h"

void loadTextures(std::vector<sf::Texture> &textureBox) {
	//Loading map texture
	sf::Texture mapTexture;
	if (!mapTexture.loadFromFile("Textures/woodfloor_c.png"))
		printf("Failure to load map texture from file.\n");
	mapTexture.setRepeated(true);
	textureBox.push_back(mapTexture);

	//Loading player texture
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("Textures/Player.png"))
		printf("Failure to load player texture from file.\n");
	textureBox.push_back(playerTexture);

	//Loading enemy texture
	sf::Texture enemyTexture;
	if (!enemyTexture.loadFromFile("Textures/Enemy.png"))
		printf("Failure to load file.\n");
	textureBox.push_back(enemyTexture);
}

void loadSprites(Player &player, std::vector<sf::Texture> &textureBox) {
	//Loading and assigning sprites for player
	sf::Sprite playerSprite;
	playerSprite.setTexture(textureBox.at(1));
	playerSprite.setScale(0.5, 0.5);

	player.setSprite(playerSprite);
}

void renderEnemies(sf::RenderWindow &window, std::vector<Enemy> &enemyBox) {
	for (int i = 0; i < enemyBox.size(); i++) {
		window.draw(enemyBox.at(i).getSprite());
	}
}

int main()
{
	//Creating the engine window
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Game Engine Window");
	window.setFramerateLimit(60);

	//Loading textures
	std::vector<sf::Texture> textureBox;
	loadTextures(textureBox);

	//Building player character
	Player player(10);

	//Creating map, enemy, and player sprites
	sf::Sprite map;
	map.setTexture(textureBox.at(0));
	map.setTextureRect({ 0,0,1200,1000 });
	loadSprites(player, textureBox);

	/* DESTOY THIS AFTER TESTING*/
	player.setX(300);
	player.setY(300);
	sf::View view(sf::FloatRect(0,0, 600, 600));
	window.setView(view);
	int x = 0;
	int y = 0;
	//Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Take player input and alter player location
		player.playerInput();
		player.getSprite().setPosition(player.getX(), player.getY());

		//Mouse Movement
		sf::RectangleShape rect;
		if (event.type == sf::Event::MouseMoved) {
			x = sf::Mouse::getPosition(window).x;
			y = sf::Mouse::getPosition(window).y;
			printf("X:%i\n", x);
			printf("Y:%i\n", y);
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			printf("Pressed\n");
			rect.setSize(sf::Vector2f(100, 100));
			rect.setPosition(x, y);
			rect.setFillColor(sf::Color(0, 0, 0, 255));
		}
		
		//Draw to the Screen
		window.clear();
		window.draw(map);
		window.draw(player.getSprite());
		window.draw(rect);

		//Camera
		view.setCenter(player.getX()+player.getSprite().getLocalBounds().width/4, player.getY()+ player.getSprite().getLocalBounds().height/4);
		window.setView(view);

		//Display the rendering
		window.display();
	}

	return 0;
}