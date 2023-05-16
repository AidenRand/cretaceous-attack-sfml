#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(float plr_width, float plr_height, float plr_x, float plr_y);
	void drawTo(sf::RenderWindow& window);
	void movePlayer();

private:
	// Normal textures
	sf::Sprite player;
	sf::Texture up_texture;
	sf::Texture down_texture;
	sf::Texture left_texture;
	sf::Texture right_texture;

	// Walking textures
	sf::Texture walkup_left_texture;
	sf::Texture walkup_right_texture;
	sf::Texture walkdown_left_texture;
	sf::Texture walkdown_right_texture;
	sf::Texture walkleft_texture;
	sf::Texture walkright_texture;
	float step = 5.0;
};

#endif