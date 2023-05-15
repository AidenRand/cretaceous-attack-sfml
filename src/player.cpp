#include "player.hpp"

Player::Player(float plr_width, float plr_height, float plr_x, float plr_y)
{
	player.setScale(sf::Vector2f(plr_width, plr_height));
	player.setPosition(sf::Vector2f(plr_x, plr_y));

	if (!up_texture.loadFromFile("content/upwards.png"))
	{
		std::cout << "ERROR: Cannot load upwards texture";
	}

	if (!down_texture.loadFromFile("content/upwards.png"))
	{
		std::cout << "ERROR: Cannot load downwards texture";
	}

	if (!left_texture.loadFromFile("content/upwards.png"))
	{
		std::cout << "ERROR: Cannot load left texture";
	}

	if (!right_texture.loadFromFile("content/upwards.png"))
	{
		std::cout << "ERROR: Cannot load right texture";
	}
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
		plr_up = false;
		plr_down = true;
	}

	// Move player left or right when A or D is pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		plr_direction.x -= step;
		plr_left = true;
		plr_right = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		plr_direction.x += step;
		plr_left = false;
		plr_right = true;
	}

	player.move(plr_direction);
}