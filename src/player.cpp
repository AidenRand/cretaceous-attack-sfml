#include "player.hpp"

Player::Player(float plr_width, float plr_height, float plr_x, float plr_y)
{
	player.setSize(sf::Vector2f(plr_width, plr_height));
	player.setPosition(sf::Vector2f(plr_x, plr_y));
	player.setFillColor(sf::Color(200, 200, 200));
}