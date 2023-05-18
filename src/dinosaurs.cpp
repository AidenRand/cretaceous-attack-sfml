#include "dinosaurs.hpp"

Dinosaurs::Dinosaurs(float dino_width, float dino_height, float dino_x, float dino_y)
{
	dinosaur.setSize(sf::Vector2f(dino_width, dino_height));
	dinosaur.setOrigin(dino_width / 2, dino_height / 2);
	dinosaur.setFillColor(sf::Color(255, 255, 255));
	dinosaur.setPosition(sf::Vector2f(dino_x, dino_y));
}