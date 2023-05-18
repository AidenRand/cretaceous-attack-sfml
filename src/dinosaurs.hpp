#ifndef DINOSAURS_HPP
#define DINOSAURS_HPP

#include <SFML/Graphics.hpp>

class Dinosaurs
{
public:
	Dinosaurs(float dino_width, float dino_height, float dino_x, float dino_y);

private:
	sf::RectangleShape dinosaur;
};

#endif