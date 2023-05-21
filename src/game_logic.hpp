#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

#include <SFML/Graphics.hpp>

class Logic
{
public:
	Logic(int& score_num, float score_x, float score_y);

private:
	sf::Font font;

	sf::Text score;
};

#endif