#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(float width, float height, float x, float y);

private:
	sf::RectangleShape bullet;
};

#endif