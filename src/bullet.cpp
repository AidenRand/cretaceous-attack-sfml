#include "bullet.hpp"
#include <SFML/Graphics.hpp>

Bullet::Bullet(float bullet_width, float bullet_height)
{
	bullet.setSize(sf::Vector2f(bullet_width, bullet_height));
	bullet.setFillColor(sf::Color(5, 5, 5));
}

void Bullet::drawTo(sf::RenderWindow& window)
{
	window.draw(bullet);
}

void Bullet::setPos(float player_x, float player_y)
{
	bullet.setPosition(sf::Vector2f(player_x, player_y));
}