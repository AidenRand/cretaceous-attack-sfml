#ifndef BULLET_HPP
#define BULLET_HPP

#include "dinosaurs.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(float width, float height, float bullet_x, float bullet_y);
	void drawTo(sf::RenderWindow& window);
	void fireBullet(Player& player_rect, int bullet_speed);
	void bulletCollision(Dinosaur& dino_rect, bool& dino_dead, bool& bullet_dead, int& score, float screen_width, float screen_height);
	void moveBullet(float dt);
	void getGunshotSound();
	void playGunshotSound();

private:
	sf::RectangleShape bullet;
	sf::Vector2f bullet_dir;

	sf::SoundBuffer gunshot_sound_buffer;
	sf::Sound gunshot_sound;
};

#endif