#include "game.hpp"
#include "bullet.hpp"
#include "dinosaurs.hpp"
#include "player.hpp"

void gameFunction(sf::RenderWindow& window, float screen_width, float screen_height)
{
	std::srand(time(NULL));
	sf::Texture background_texture;
	sf::Sprite background;
	if (!background_texture.loadFromFile("content/background.png"))
	{
		std::cout << "ERROR: Cannot load background image";
	}
	background.setTexture(background_texture);
	float background_x = -55;
	float background_y = -180;
	background.setPosition(sf::Vector2f(background_x, background_y));
	window.setFramerateLimit(60);

	// Create player
	float plr_width = 1;
	float plr_height = 1;
	float plr_x = 610;
	float plr_y = 482;
	Player player(plr_width, plr_height, plr_x, plr_y);

	// Create bullet variables
	float bullet_width = 3;
	float bullet_height = 3;
	float bullet_x = 640;
	float bullet_y = 505;
	float bullet_speed = 20;
	unsigned int reload_timer = 0;
	int cooldown = 10;
	bool bullet_firing = false;
	Bullet bullet(bullet_width, bullet_height);
	std::vector<Bullet> bullet_vector;

	// Create dinosaur variables
	float dino_width = 20;
	float dino_height = 20;
	float dino_speed = 5;
	bool dino_dead = false;
	std::vector<Dinosaurs> dino_vector;
	long unsigned int max_dinos = 2;

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

			// If the bullet goes off screen, delete it
			if (bullet_vector[i].returnX() > screen_width
				|| bullet_vector[i].returnX() < 0
				|| bullet_vector[i].returnY() > screen_height
				|| bullet_vector[i].returnY() < 0)
			{
				bullet_vector.erase(bullet_vector.begin() + i);
			}
		}

		// Create dinosaurs
		Dinosaurs dinosaur(dino_width, dino_height);
		dinosaur.spawnDinosaurs(screen_width, screen_height);

		// Push dinosaurs to dino_vector
		if (dino_vector.size() < max_dinos)
		{
			dino_vector.push_back(dinosaur);
		}

		for (long unsigned int i = 0; i != dino_vector.size(); i++)
		{
			// If dino_dead == false, spawn and move dinosaurs
			if (!dino_dead)
			{
				dino_vector[i].moveDinosaurs(dino_speed);
				dino_vector[i].drawTo(window);
			}
			dino_vector[i].killDinosaurs(dino_dead, player);

			// If dino_dead == true, delete dinosaur
			if (dino_dead)
			{
				dino_vector.erase(dino_vector.begin() + i);
				dino_dead = false;
			}
		}

		player.drawTo(window);
		player.changePlayerTexture();
		window.display();
	}
}