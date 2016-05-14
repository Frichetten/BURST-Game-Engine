#include <stdio.h>
#include "Character.h"
//#include <SFML/Graphics.hpp>

int n = 5;

Character::Character() {
	printf("Successfully created a character\n");
}

void Character::moveLeft(int &x) {
	x = x - n;
}

void Character::moveRight(int &x) {
	x = x + n;
}

void Character::moveUp(int &y) {
	y = y - n;
}

void Character::moveDown(int &y) {
	y = y + n;
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

Player::Player() {
	printf("Successfully created a player\n");
	this->x = 0;
	this->y = 0;
	this->health = 10;
	this->mana = 7;
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

Enemy::Enemy() {
	printf("Successfully created a Enemy\n");
	this->x = 0;
	this->y = 0;
	this->health = 7;
	this->mana = 5;
}

void Enemy::setSprite(sf::Sprite enemySprite) {
	this->enemySprite = enemySprite;
}

sf::Sprite& Enemy::getSprite() {
	return this->enemySprite;
}