#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <SFML/Graphics.hpp>

class Logic
{
public:
	Logic(int& score_num, float score_x, float score_y, int& lives_num, float lives_x, float lives_y, std::string end_text_string, float& end_text_x, float& end_text_y);
	void drawScore(sf::RenderWindow& window);
	void drawLives(sf::RenderWindow& window);
	void endGame(sf::RenderWindow& window, int& score, int& lives_left, int& dino_speed);

private:
	sf::Font font;
	int font_size = 50;
	sf::Color white = sf::Color(200, 200, 200);

	sf::Text score_text;
	sf::Text lives_left;
	sf::Text end_text;
};

#endif