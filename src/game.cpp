#include "game.hpp"
#include "bullet.hpp"
#include "dinosaurs.hpp"
#include "logic.hpp"
#include "player.hpp"

void gameFunction(sf::RenderWindow& window, float screen_width, float screen_height)
{
	std::srand(time(NULL));

	sf::Texture background_texture;
	sf::Sprite background;
	if (!background_texture.loadFromFile("content/background.jpeg"))
	{
		std::cout << "ERROR: Cannot load background image";
	}
	background.setTexture(background_texture);
	float background_x = 10;
	float background_y = -120;
	background.setPosition(sf::Vector2f(background_x, background_y));

	// Score variables
	int score = 0;
	float score_x = 100.0;
	float score_y = 50.0;

	// Lives left variables
	int lives_left = 5;
	float lives_x = 1150.0;
	float lives_y = 50.0;

	// Create player
	float plr_width = 1;
	float plr_height = 1;
	float plr_x = 610;
	float plr_y = 482;
	Player player(plr_width, plr_height, plr_x, plr_y);

	// Bullet variables
	float bullet_width = 5;
	float bullet_height = 5;
	float bullet_x = 640;
	float bullet_y = 505;
	float bullet_speed = 50;
	int cooldown = 10;
	unsigned int reload_timer = 0;
	bool bullet_firing = false;
	bool bullet_dead = false;
	std::vector<Bullet> bullet_vector;
	Bullet bullet(bullet_width, bullet_height);

	// Dinosaur variables
	float dino_width = 1;
	float dino_height = 1;
	float dino_speed = 10;
	bool dino_dead = false;

	// Create dinosaurs
	Dinosaurs dinosaur(dino_width, dino_height);
	dinosaur.spawnDinosaurs(screen_width, screen_height);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			// If space is pressed fire bullet
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::S)
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::A)
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				bullet_firing = true;
			}
		}
		window.clear();
		window.draw(background);

		// If the reload timer is zero, allow bullet to be fired
		if (reload_timer == 0)
		{
			if (bullet_firing)
			{
				bullet.fireBullet(player, bullet_speed);
				bullet.setPos(bullet_x, bullet_y);
				bullet_firing = false;
				reload_timer += cooldown;
				bullet_vector.push_back(bullet);
			}
		}
		else
		{
			reload_timer--;
		}

		// Draw bullet to window
		for (long unsigned int i = 0; i < bullet_vector.size(); i++)
		{
			bullet_vector[i].moveBullet();
			bullet_vector[i].drawTo(window);
			bullet_vector[i].bulletCollision(dinosaur, dino_dead, bullet_dead, score, screen_height, screen_width);

			// If the bullet goes off screen, delete it
			if (bullet_dead)
			{
				bullet_vector.erase(bullet_vector.begin() + i);
				bullet_dead = false;
			}
		}

		// If dinosaur is not dead move and spawn dinosaur,
		// If dinosaur is dead give dinosaur new position
		if (!dino_dead)
		{
			dinosaur.moveDinosaurs(dino_speed);
			dinosaur.drawTo(window);
		}
		dinosaur.killDinosaurs(dino_dead, player, lives_left);

		// If dino_dead == true, reset dinosaur
		if (dino_dead)
		{
			dinosaur.resetDinosaur(screen_width, screen_height);
			dino_dead = false;
		}

		// Create score and lives left
		Logic logic(score, score_x, score_y, lives_left, lives_x, lives_y);

		logic.drawScore(window);
		logic.drawLives(window);
		player.drawTo(window);
		player.changePlayerTexture();
		window.display();
	}
}