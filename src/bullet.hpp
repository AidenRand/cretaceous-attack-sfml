#ifndef BULLET_HPP
#define BULLET_HPP

#include "player.hpp"
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(float width, float height);
	void drawTo(sf::RenderWindow& window);
	void setPos(float player_x, float player_y);
	void fireBullet(Player& player_rect, float bullet_speed);
	void moveBullet();

private:
	sf::RectangleShape bullet;
	sf::Vector2f bullet_dir;
};

#endif