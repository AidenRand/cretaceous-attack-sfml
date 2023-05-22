#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <SFML/Graphics.hpp>

class Logic
{
public:
	Logic(int& score_num, float score_x, float score_y, int& lives_num, float lives_x, float lives_y);
	void drawScore(sf::RenderWindow& window);
	void drawLives(sf::RenderWindow& window);
	void endGame(bool& end_game, int& lives_left);

private:
	sf::Font font;
	int font_size = 50;
	sf::Color white = sf::Color(200, 200, 200);

	sf::Text score_text;
	sf::Text lives_left;
};

#endif