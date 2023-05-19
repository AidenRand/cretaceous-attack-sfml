#ifndef DINOSAURS_HPP
#define DINOSAURS_HPP

#include "player.hpp"
#include <SFML/Graphics.hpp>

class Dinosaurs
{
public:
	Dinosaurs(float dino_width, float dino_height);
	void spawnDinosaurs(float screen_width, float screen_height);
	void drawTo(sf::RenderWindow& window);
	void moveDinosaurs(float dino_speed);
	void killDinosaurs(bool& dino_dead, Player& player_rect);

private:
	sf::RectangleShape dinosaur;
	sf::Vector2f position;
	sf::Vector2f direction;

	// Coordinates for spawn locations on four sides of window
	int random_side;
	sf::Vector2f side_one;
	sf::Vector2f side_two;
	sf::Vector2f side_three;
	sf::Vector2f side_four;

	bool move_up = false;
	bool move_down = false;
	bool move_left = false;
	bool move_right = false;
};

#endif