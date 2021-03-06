#include <SFML/Graphics.hpp>

class Character {

	int health;
	int mana;
	int x;
	int y;

	public:
		Character();
		Character(int health);
		void moveLeft(int &x);
		void moveRight(int &x);
		void moveUp(int &y);
		void moveDown(int &y);
};

class Player : public Character {

	int health;
	int mana;
	int x;
	int y;
	sf::Sprite sprite;

	public:
		Player(int health);
		void playerInput();
		void setSprite(sf::Sprite playerSprite);
		sf::Sprite& getSprite();
		void animateRight(Player &player, sf::Texture texture);
		int getX();
		int getY();
		void setX(int num);
		void setY(int num);
};

class Enemy : public Character {

	int health;
	int mana;
	int x;
	int y;
	sf::Sprite enemySprite;

	public:
		Enemy(int health);
		int getX();
		int getY();
		int getHealth();
		void setSprite(sf::Sprite playerSprite);
		sf::Sprite& getSprite();
		void setX(int num);
		void setY(int num);
		void moveRight(int &x);
		void moveUp(int &y);
		void moveDown(int &y);
		void moveLeft(int &x);

		void movement(int x, int y, sf::Sprite &sprite);
};