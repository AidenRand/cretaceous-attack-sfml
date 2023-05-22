#include "logic.hpp"

Logic::Logic(int& score_num, float score_x, float score_y, int& lives_num, float lives_x, float lives_y)
{
	// Add leading zeros to score
	size_t n = 3;
	std::string score_string = std::to_string(score_num);
	int precision = n - std::min(n, score_string.size());
	std::string score = std::string(precision, '0').append(score_string);
	score_text.setString(score);
	score_text.setPosition(sf::Vector2f(score_x, score_y));

	std::string lives_string = std::to_string(lives_num);
	lives_left.setString(lives_string);
	lives_left.setPosition(sf::Vector2f(lives_x, lives_y));

	font.loadFromFile("content/8_bit_party.ttf");
}

void Logic::drawScore(sf::RenderWindow& window)
{
	// Print score to screen
	score_text.setFont(font);
	score_text.setCharacterSize(font_size);
	score_text.setFillColor(white);
	window.draw(score_text);
}

void Logic::drawLives(sf::RenderWindow& window)
{
	// Print lives left to screen
	lives_left.setFont(font);
	lives_left.setCharacterSize(font_size);
	lives_left.setFillColor(white);
	window.draw(lives_left);
}