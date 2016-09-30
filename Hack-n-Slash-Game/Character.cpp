#include <stdio.h>
#include "Character.h"
//#include <SFML/Graphics.hpp>

int n = 5;
int e = 2;

Character::Character() {
	printf("Defualt Constructor\n");
}

Character::Character(int health) {
	printf("Successfully created a character\n");
	this->health = health;
}

void Character::moveLeft(int &x) {
	x = x - n;
}

void Enemy::moveLeft(int &x) {
	x = x - e;
}

void Character::moveRight(int &x) {
	x = x + n;
}

void Enemy::moveRight(int &x) {
	x = x + e;
}

void Character::moveUp(int &y) {
	y = y - n;
}

void Enemy::moveUp(int &y) {
	y = y - e;
}

void Character::moveDown(int &y) {
	y = y + n;
}

void Enemy::moveDown(int &y) {
	y = y + e;
}

int Player::getX() {
	return this->x;
}

int Player::getY() {
	return this->y;
}

int Enemy::getX() {
	return this->x;
}

int Enemy::getY() {
	return this->y;
}

void Enemy::setX(int num) {
	this->x = num;
}

void Enemy::setY(int num) {
	this->y = num;
}

int Enemy::getHealth() {
	return this->health;
}

Player::Player(int health) {
	printf("Successfully created a player\n");
	this->x = 0;
	this->y = 0;
	this->health = health;
	this->mana = 7;
}

void Player::setX(int num) {
	this->x = num;
}

void Player::setY(int num) {
	this->y = num;
}

void Player::setSprite(sf::Sprite playerSprite) {
	this->sprite = playerSprite;
}

sf::Sprite& Player::getSprite() {
	return this->sprite;
}

void Player::playerInput() {
	//printf("X:%i Y:%i\n", this->getX, this->getY);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->moveRight(this->x);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->moveDown(this->y);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->moveUp(this->y);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->moveLeft(this->x);
}

void Player::animateRight(Player &player, sf::Texture texture) {
	player.getSprite().setTexture(texture);
}

Enemy::Enemy(int health) {
	printf("Successfully created a Enemy\n");
	this->x = 0;
	this->y = 0;
	this->health = health;
	this->mana = 5;
}

void Enemy::setSprite(sf::Sprite enemySprite) {
	this->enemySprite = enemySprite;
}

sf::Sprite& Enemy::getSprite() {
	return this->enemySprite;
}

void Enemy::movement(int x, int y, sf::Sprite &sprite) {
	if (this->x < x) {
		this->moveRight(this->x);
		this->getSprite().setPosition(this->x, this->y);
	}
	else if (this->x > x) {
		this->moveLeft(this->x);
		this->getSprite().setPosition(this->x, this->y);
	}

	if (this->y < y) {
		this->moveDown(this->y);
		this->getSprite().setPosition(this->x, this->y);
	}
	else if (this->y > y) {
		this->moveUp(this->y);
		this->getSprite().setPosition(this->x, this->y);
	}
}