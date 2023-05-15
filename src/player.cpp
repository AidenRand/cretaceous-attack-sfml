#include "player.hpp"

Player::Player(float plr_width, float plr_height, float plr_x, float plr_y)
{
	player.setSize(sf::Vector2f(plr_width, plr_height));
	player.setPosition(sf::Vector2f(plr_x, plr_y));
	player.setFillColor(sf::Color(200, 200, 200));
}

void Player::movePlayer()
{
	sf::Vector2f plr_direction;

	// Move player up or down when W or S is pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		plr_direction.y -= step;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		plr_direction.y += step;
	}

	// Move player left or right when A or D is pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		plr_direction.x -= step;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		plr_direction.x += step;
	}

	player.move(plr_direction);
}

void Player::drawTo(sf::RenderWindow& window)
{
	window.draw(player);
}