#include "projectile.h"

projectile::projectile()
{
	rect.setSize(sf::Vector2f(25, 25));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Green);
	//sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
}
void projectile::update()
{
	if (direction == 1)
	{
		rect.move(-movementspeed, 0);
	}
	if (direction == 2)
	{
		rect.move(movementspeed, 0);
	}
	if (direction == 3)
	{
		rect.move(0, -movementspeed);
	}
	if (direction == 4)
	{
		rect.move(0, movementspeed);
	}
	counterLifetime++;
	if (counterLifetime >= lifeTime)
	{
		destroy = true;
	}
}
