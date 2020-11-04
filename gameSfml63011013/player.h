
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class player
{
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
	float movementspeed = 0.5;
	int attackDamage = 5;
	int counterWallking = 0;
	int direction = 0;
	int hp = 10;

	player();
	void update();
	void updateMovement();
private:
protected:
};

