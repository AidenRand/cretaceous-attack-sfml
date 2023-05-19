#include "dinosaurs.hpp"
#include "player.hpp"

Dinosaurs::Dinosaurs(float dino_width, float dino_height)
{
	dinosaur.setSize(sf::Vector2f(dino_width, dino_height));
	dinosaur.setOrigin(dino_width / 2, dino_height / 2);
	dinosaur.setFillColor(sf::Color(255, 255, 255));
}

void Dinosaurs::spawnDinosaurs(float screen_width, float screen_height)
{
	random_side = rand() % 4;
	// Spawn dinosaur on side corresponding to random number generated
	if (random_side == 0)
	{
		side_one.x = screen_width / 2;
		side_one.y = 0;
		position = side_one;
		move_down = true;
	}
	else if (random_side == 1)
	{
		side_two.x = screen_width;
		side_two.y = screen_height / 2;
		position = side_two;
		move_left = true;
	}
	else if (random_side == 2)
	{
		side_three.x = screen_width / 2;
		side_three.y = screen_height;
		position = side_three;
		move_up = true;
	}
	else if (random_side == 3)
	{
		side_four.x = 0;
		side_four.y = screen_height / 2;
		position = side_four;
		move_right = true;
	}
	dinosaur.setPosition(position);
}

void Dinosaurs::drawTo(sf::RenderWindow& window)
{
	window.draw(dinosaur);
}

void Dinosaurs::moveDinosaurs(float dino_speed)
{
	// Move in direction corresponding to side generated
	if (move_down)
	{
		direction.x = 0;
		direction.y = dino_speed;
	}
	if (move_left)
	{
		direction.x = -dino_speed;
		direction.y = 0;
	}
	if (move_up)
	{
		direction.x = 0;
		direction.y = -dino_speed;
	}
	if (move_right)
	{
		direction.x = dino_speed;
		direction.y = 0;
	}
	dinosaur.move(direction);
}

void Dinosaurs::killDinosaurs(bool& dino_dead, Player& player_rect)
{
	dino_dead = false;
	auto player = player_rect.player;

	// If dino and player collide set dino_dead to true
	if (dinosaur.getGlobalBounds().intersects(player.getGlobalBounds()))
	{
		dino_dead = true;
	}
}
