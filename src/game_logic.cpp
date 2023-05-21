#include "game_logic.hpp"

Logic::Logic(int& score_num, float score_x, float score_y)
{
	std::string score_string = std::to_string(score_num);
	score.setString(score_string);
	score.setPosition(sf::Vector2f(score_x, score_y));

	font.loadFromFile("content/8_bit_party.ttf");
}

void Logic::drawScore(sf::RenderWindow& window)
{

	// Print score to screen
	score.setFont(font);
	score.setCharacterSize(font_size);
	score.setFillColor(sf::Color(200, 200, 200));
	window.draw(score);
}