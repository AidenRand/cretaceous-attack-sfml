#include "logic.hpp"

Logic::Logic(int& score_num, float score_x, float score_y, int& lives_num, float lives_x, float lives_y, std::string end_text_string, float& end_text_x, float& end_text_y)
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

	end_text.setString(end_text_string);
	end_text.setCharacterSize(font_size);
	end_text.setFont(font);
	end_text.setFillColor(white);
	end_text.setPosition(sf::Vector2f(end_text_x, end_text_y));

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

void Logic::endGame(sf::RenderWindow& window, int& score, int& lives_left, int& dino_speed)
{
	dino_speed = 0;
	window.draw(end_text);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		score = 0;
		lives_left = 5;
		dino_speed = 10;
	}
}
