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
		side_spawn.x = screen_width / 2;
		side_spawn.y = 0;
		move_down = true;
	}
	else if (random_side == 1)
	{
		side_spawn.x = screen_width;
		side_spawn.y = screen_height / 2;
		move_left = true;
	}
	else if (random_side == 2)
	{
		side_spawn.x = screen_width / 2;
		side_spawn.y = screen_height;
		move_up = true;
	}
	else if (random_side == 3)
	{
		side_spawn.x = 0;
		side_spawn.y = screen_height / 2;
		move_right = true;
	}
	dinosaur.setPosition(side_spawn);
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
	auto player = player_rect.player;

	// If dino and player collide set dino_dead = true
	if (dinosaur.getGlobalBounds().intersects(player.getGlobalBounds()))
	{
		dino_dead = true;
	}
}

void Dinosaurs::resetDinosaur(float screen_width, float screen_height)
{
	spawnDinosaurs(screen_width, screen_height);
}