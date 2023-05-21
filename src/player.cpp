#include "player.hpp"

Player::Player(float plr_width, float plr_height, float plr_x, float plr_y)
{
	player.setScale(sf::Vector2f(plr_width, plr_height));
	player.setPosition(sf::Vector2f(plr_x, plr_y));

	// Fetch shooting player textures
	up_texture.loadFromFile("content/forward-player.png");
	down_texture.loadFromFile("content/downward-player.png");
	left_texture.loadFromFile("content/left-player.png");
	right_texture.loadFromFile("content/right-player.png");

	player.setTexture(down_texture);
}

void Player::drawTo(sf::RenderWindow& window)
{
	window.draw(player);
}

void Player::changePlayerTexture()
{
	// Change player direction when W or S is pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{

		player.setTexture(up_texture);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player.setTexture(down_texture);
	}

	// Change player direction when A or D is pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.setTexture(left_texture);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.setTexture(right_texture);
	}
}