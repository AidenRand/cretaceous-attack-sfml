#include "bullet.hpp"
#include "player.hpp"
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

void Bullet::fireBullet(Player& player_rect, float bullet_speed)
{
	auto player = player_rect.player;

	// Fire Bullets in the direction the player is facing
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		bullet_dir.x = -bullet_speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		bullet_dir.x = bullet_speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		bullet_dir.y = -bullet_speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		bullet_dir.x = bullet_speed;
	}
}

void Bullet::moveBullet()
{
	bullet.move(bullet_dir);
}