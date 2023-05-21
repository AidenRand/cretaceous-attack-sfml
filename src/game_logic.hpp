#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

#include <SFML/Graphics.hpp>

class Logic
{
public:
	Logic(int& score_num, float score_x, float score_y);
	void drawScore(sf::RenderWindow& window);

private:
	sf::Font font;
	int font_size = 50;

	sf::Text score;
};

#endif