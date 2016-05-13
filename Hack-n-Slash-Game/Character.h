class Character {

	int health;
	int mana;
	int x;
	int y;

	public:
		Character();
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

	public:
		Player();
		void playerInput();
		int getX();
		int getY();
};

class Enemy : public Character {

	int health;
	int mana;
	int x;
	int y;

	public:
		Enemy();
		int getX();
		int getY();
		void setX(int num);
		void setY(int num);
};