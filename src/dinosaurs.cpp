#include "dinosaurs.hpp"
#include "player.hpp"

Dinosaur::Dinosaur(float dino_width, float dino_height)
{
	dinosaur.setOrigin(dino_width / 2, dino_height / 2);

	// Fetch dinosaur textures
	top_dino_texture.loadFromFile("content/top-dinosaur.png");
	bottom_dino_texture.loadFromFile("content/bottom-dinosaur.png");
	left_dino_texture.loadFromFile("content/left-dinosaur.png");
	right_dino_texture.loadFromFile("content/right-dinosaur.png");

	total_time = 0.0f;
	current_image.x = 0;

	bottom_uv_rect.width = bottom_dino_texture.getSize().x / float(image_count.x);
	bottom_uv_rect.height = bottom_dino_texture.getSize().y / float(image_count.y);

	right_uv_rect.width = right_dino_texture.getSize().x / float(image_count.x);
	right_uv_rect.height = right_dino_texture.getSize().y / float(image_count.y);

	left_uv_rect.width = left_dino_texture.getSize().x / float(image_count.x);
	left_uv_rect.height = left_dino_texture.getSize().y / float(image_count.y);
}

void Dinosaur::spawnDinosaur(float screen_width, float screen_height, float& dino_width, float& dino_height)
{
	random_side = rand() % 4;

	// Spawn dinosaur on side corresponding to random number generated
	if (random_side == 0)
	{
		dinosaur.setTexture(top_dino_texture, true);
		side_spawn.x = (screen_width / 2) + placement_correction;
		side_spawn.y = -dino_height;
		move_up = false;
		move_down = true;
		move_left = false;
		move_right = false;
	}
	else if (random_side == 1)
	{
		dinosaur.setTexture(right_dino_texture, true);
		side_spawn.x = screen_width + dino_width;
		side_spawn.y = (screen_height / 2);
		move_up = false;
		move_down = false;
		move_left = true;
		move_right = false;
	}
	else if (random_side == 2)
	{
		dinosaur.setTexture(bottom_dino_texture, true);
		side_spawn.x = (screen_width / 2) + placement_correction;
		side_spawn.y = screen_height + dino_width;
		move_up = true;
		move_down = false;
		move_left = false;
		move_right = false;
	}
	else if (random_side == 3)
	{
		dinosaur.setTexture(left_dino_texture, true);
		side_spawn.x = -dino_width - (placement_correction * 5);
		side_spawn.y = (screen_height / 2) - (placement_correction * 2);
		move_up = false;
		move_down = false;
		move_left = false;
		move_right = true;
	}
	dinosaur.setPosition(side_spawn);
}

void Dinosaur::drawTo(sf::RenderWindow& window)
{
	window.draw(dinosaur);
}

void Dinosaur::animateDinosaur(int row, float dt)
{
	// Loop back and forth through textures in sprite sheet
	current_image.y = row;
	total_time += dt;

	if (total_time >= switch_time)
	{
		total_time -= switch_time;
		current_image.x++;
		if (current_image.x >= image_count.x)
		{
			current_image.x = 0;
		}
	}

	bottom_uv_rect.left = current_image.x * bottom_uv_rect.width;
	bottom_uv_rect.top = current_image.y * bottom_uv_rect.height;

	right_uv_rect.left = current_image.x * right_uv_rect.width;
	right_uv_rect.top = current_image.y * right_uv_rect.height;

	left_uv_rect.left = current_image.x * left_uv_rect.width;
	left_uv_rect.top = current_image.y * left_uv_rect.height;
}

void Dinosaur::moveDinosaur(int dino_speed)
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
		dinosaur.setTextureRect(right_uv_rect);
	}
	if (move_up)
	{
		direction.x = 0;
		direction.y = -dino_speed;
		dinosaur.setTextureRect(bottom_uv_rect);
	}
	if (move_right)
	{
		direction.x = dino_speed;
		direction.y = 0;
		dinosaur.setTextureRect(left_uv_rect);
	}
	dinosaur.move(direction);
}

void Dinosaur::killDinosaur(bool& dino_dead, Player& player_rect, int& lives_left)
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