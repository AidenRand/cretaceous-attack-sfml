#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(float width, float height);
	void drawTo(sf::RenderWindow& window);
	void setPos(float player_x, float player_y);

private:
	sf::RectangleShape bullet;
};

#endif