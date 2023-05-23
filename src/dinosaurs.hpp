#ifndef DINOSAURS_HPP
#define DINOSAURS_HPP

#include "player.hpp"
#include <SFML/Graphics.hpp>

class Dinosaur
{
public:
	Dinosaur(float dino_width, float dino_height);
	void spawnDinosaur(float screen_width, float screen_height, float& dino_width, float& dino_height);
	void drawTo(sf::RenderWindow& window);
	void animateDinosaur(int row, float dt);
	void moveDinosaur(int dino_speed);
	void killDinosaur(bool& dino_dead, Player& player_rect, int& lives_left);
	sf::Sprite dinosaur;

private:
	sf::Vector2f direction;

	// Coordinates for spawn locations on four sides of window
	int random_side;
	sf::Vector2f side_spawn;
	int placement_correction = 30;

	sf::Texture top_dino_texture;
	sf::Texture bottom_dino_texture;
	sf::Texture left_dino_texture;
	sf::Texture right_dino_texture;

	sf::IntRect bottom_uv_rect;
	sf::IntRect right_uv_rect;
	sf::IntRect left_uv_rect;
	float total_time;
	float switch_time = 0.1f;
	sf::Vector2u image_count = sf::Vector2u(8, 1);
	sf::Vector2u current_image;

	bool move_up;
	bool move_down;
	bool move_left;
	bool move_right;
};

#endif