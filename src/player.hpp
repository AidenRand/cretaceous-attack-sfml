#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(float plr_width, float plr_height, float plr_x, float plr_y);
	void movePlayer();
	void drawTo(sf::RenderWindow& window);

private:
	sf::RectangleShape player;
	float step = 5.0;
};

#endif