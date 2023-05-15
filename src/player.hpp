#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(float plr_width, float plr_height, float plr_x, float plr_y);

private:
	sf::RectangleShape player;
};

#endif