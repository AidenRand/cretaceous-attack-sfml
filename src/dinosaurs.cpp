#include "dinosaurs.hpp"

Dinosaurs::Dinosaurs(float dino_width, float dino_height, float dino_x, float dino_y)
{
	dinosaur.setSize(sf::Vector2f(dino_width, dino_height));
	dinosaur.setOrigin(dino_width / 2, dino_height / 2);
	dinosaur.setFillColor(sf::Color(255, 255, 255));
	dinosaur.setPosition(sf::Vector2f(dino_x, dino_y));
}

void Dinosaurs::spawnDinosaurs(float screen_width, float screen_height)
{
	// Spawn dinosaur on side corresponding to random number generated
	if (random_side == 1)
	{
		side_one.x = screen_width / 2;
		side_one.y = 0;
		dinosaur.setPosition(side_one);
	}
	else if (random_side == 2)
	{
		side_two.x = screen_width;
		side_two.y = screen_height / 2;
		dinosaur.setPosition(side_two);
	}
	else if (random_side == 3)
	{
		side_three.x = screen_width / 2;
		side_three.y = screen_height;
		dinosaur.setPosition(side_three);
	}
	else if (random_side == 4)
	{
		side_four.x = 0;
		side_four.y = 0;
		dinosaur.setPosition(side_four);
	}
}