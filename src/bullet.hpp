#ifndef BULLET_HPP
#define BULLET_HPP

#include "dinosaurs.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(float width, float height);
	void drawTo(sf::RenderWindow& window);
	void setPos(float player_x, float player_y);
	void fireBullet(Player& player_rect, float bullet_speed);
	void bulletCollision(Dinosaurs& dino_rect, bool& dino_dead, bool& bullet_dead, float screen_width, float screen_height);
	void moveBullet();
	float returnX();
	float returnY();

private:
	sf::RectangleShape bullet;
	sf::Vector2f bullet_dir;
};

#endif