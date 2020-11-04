#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class projectile
{
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
	int movementspeed = 3;
	int attack = 5;
	int direction = 0;
	bool destroy = false;
	int counterLifetime = 0;
	int lifeTime = 100;


	projectile();
	void update();
	//void updateMovement();
};


