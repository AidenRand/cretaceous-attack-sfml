#ifndef DINOSAURS_HPP
#define DINOSAURS_HPP

#include <SFML/Graphics.hpp>

class Dinosaurs
{
public:
	Dinosaurs(float dino_width, float dino_height, float dino_x, float dino_y);
	void spawnDinosaurs(float screen_width, float screen_height);

private:
	sf::RectangleShape dinosaur;
	sf::Vector2f direction;
	// Coordinates for spawn locations on four sides of window
	int random_side = rand() % 4;
	sf::Vector2f side_one;
	sf::Vector2f side_two;
	sf::Vector2f side_three;
	sf::Vector2f side_four;
};

#endif