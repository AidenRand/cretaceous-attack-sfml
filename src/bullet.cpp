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

	sf::Vector2f bullet_dir;

	if (player_rect.facing_left)
	{
		bullet_dir.x -= bullet_speed;
	}
	else if (player_rect.facing_right)
	{
		bullet_dir.x += bullet_speed;
	}

	if (player_rect.facing_up)
	{
		bullet_dir.y -= bullet_speed;
	}
	else if (player_rect.facing_down)
	{
		bullet_dir.x += bullet_speed;
	}
	bullet.move(bullet_dir);
}