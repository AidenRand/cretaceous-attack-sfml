#include "dinosaurs.hpp"
#include "player.hpp"

Dinosaurs::Dinosaurs(float dino_width, float dino_height)
{
	dinosaur.setOrigin(dino_width, dino_height);

	// Fetch dinosaur textures
	top_dino_texture.loadFromFile("content/top-dinosaur.png");
	bottom_dino_texture.loadFromFile("content/bottom-dinosaur.png");
	left_dino_texture.loadFromFile("content/left-dinosaur.png");
	right_dino_texture.loadFromFile("content/right-dinosaur.png");
}

void Dinosaurs::spawnDinosaurs(float screen_width, float screen_height)
{
	random_side = rand() % 4;
	// Spawn dinosaur on side corresponding to random number generated
	if (random_side == 0)
	{
		dinosaur.setTexture(top_dino_texture, true);
		side_spawn.x = screen_width / 2;
		side_spawn.y = 0;
		move_up = false;
		move_down = true;
		move_left = false;
		move_right = false;
	}
	else if (random_side == 1)
	{
		dinosaur.setTexture(right_dino_texture, true);
		side_spawn.x = screen_width;
		side_spawn.y = (screen_height / 2) - 10;
		move_up = false;
		move_down = false;
		move_left = true;
		move_right = false;
	}
	else if (random_side == 2)
	{
		dinosaur.setTexture(bottom_dino_texture, true);
		side_spawn.x = screen_width / 2;
		side_spawn.y = screen_height;
		move_up = true;
		move_down = false;
		move_left = false;
		move_right = false;
	}
	else if (random_side == 3)
	{
		dinosaur.setTexture(left_dino_texture, true);
		side_spawn.x = 0;
		side_spawn.y = (screen_height / 2) - 50;
		move_up = false;
		move_down = false;
		move_left = false;
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

void Dinosaurs::killDinosaurs(bool& dino_dead, Player& player_rect, int& lives_left)
{
	auto player = player_rect.player;

	// If dino and player collide set dino_dead = true
	// and decrement lives_left
	if (dinosaur.getGlobalBounds().intersects(player.getGlobalBounds()))
	{
		dino_dead = true;
		lives_left--;
	}
}

void Dinosaurs::resetDinosaur(float screen_width, float screen_height)
{
	spawnDinosaurs(screen_width, screen_height);
}