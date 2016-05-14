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

void loadSprites(Player &player, std::vector<Enemy> &enemyBox, std::vector<sf::Texture> &textureBox) {
	//Loading and assigning sprites for player
	sf::Sprite playerSprite;
	playerSprite.setTexture(textureBox.at(1));
	playerSprite.setScale(0.5, 0.5);

	player.setSprite(playerSprite);

	//Loading and assigning sprites for enemy
	for (int i = 0; i < enemyBox.size(); i++) {
		sf::Sprite enemySprite;
		enemyBox.at(i).setSprite(enemySprite);
		enemyBox.at(i).getSprite().setTexture(textureBox.at(2));
		enemyBox.at(i).getSprite().setScale(0.5, 0.5);
		enemyBox.at(i).getSprite().setPosition(enemyBox.at(i).getX(), enemyBox.at(i).getY());
	}
}

void renderEnemies(sf::RenderWindow &window, std::vector<Enemy> &enemyBox) {
	for (int i = 0; i < enemyBox.size(); i++) {
		window.draw(enemyBox.at(i).getSprite());
	}
}

int main()
{
	//Creating the engine window
	sf::RenderWindow window(sf::VideoMode(700, 700), "Game Engine Window");
	window.setFramerateLimit(60);

	//Loading textures
	std::vector<sf::Texture> textureBox;
	loadTextures(textureBox);

	//Building player character
	Player player;

	//Building enemies
	srand(time(0));
	std::vector<Enemy> enemyBox;
	for (int i = 0; i < 3; i++) {
		Enemy enemy;
		enemy.setX(rand() % 750);
		enemy.setY(rand() % 750);
		enemyBox.push_back(enemy);
	}

	//Creating map, enemy, and player sprites
	sf::Sprite map;
	map.setTexture(textureBox.at(0));
	map.setTextureRect({ 0,0,1000,1000 });
	loadSprites(player, enemyBox, textureBox);

	sf::RectangleShape healthBar(sf::Vector2f(100,50));
	healthBar.setFillColor(sf::Color::Blue);
	healthBar.setPosition(10, 600);

	/* DESTOY THIS AFTER TESTING*/
	player.setX(300);
	player.setY(300);
	sf::View view(sf::FloatRect(0,0, 600, 600));
	window.setView(view);

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

		//Handle enemy AI actions
		//Enemies movement actions
		for (int i = 0; i < enemyBox.size(); i++) {
			enemyBox.at(i).movement(player.getX(), player.getY(), enemyBox.at(i).getSprite());
		}
		
		window.clear();
		window.draw(map);
		window.draw(player.getSprite());
		
		//Render enemy sprites
		renderEnemies(window, enemyBox);

		//Render UI
		healthBar.setPosition(player.getX() - 200, player.getY() + 300);
		window.draw(healthBar);

		//Camera
		view.setCenter(player.getX()+player.getSprite().getLocalBounds().width/4, player.getY()+ player.getSprite().getLocalBounds().height/4);
		window.setView(view);

		window.display();
	}

	return 0;
}