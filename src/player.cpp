#include "player.hpp"

Player::Player(float plr_width, float plr_height, float plr_x, float plr_y)
{
	player.setScale(sf::Vector2f(plr_width, plr_height));
	player.setPosition(sf::Vector2f(plr_x, plr_y));

	// Fetch shooting player textures
	up_texture.loadFromFile("content/forward-gun.png");
	down_texture.loadFromFile("content/downward-gun.png");
	left_texture.loadFromFile("content/left-gun.png");
	right_texture.loadFromFile("content/right-gun.png");

	player.setTexture(down_texture);
}

void Player::drawTo(sf::RenderWindow& window)
{
	window.draw(player);
}

void Player::movePlayer()
{
	sf::Vector2f plr_direction;

	// Move player up or down when W or S is pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{

		plr_direction.y -= step;
		player.setTexture(up_texture);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		plr_direction.y += step;
		player.setTexture(down_texture);
	}

	// Move player left or right when A or D is pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		plr_direction.x -= step;
		player.setTexture(left_texture);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		plr_direction.x += step;
		player.setTexture(right_texture);
	}

	player.move(plr_direction);
}

float Player::returnXPos()
{
	float x_pos = player.getPosition().x;
	return x_pos;
}

float Player::returnYPos()
{
	float y_pos = player.getPosition().y;
	return y_pos;
}