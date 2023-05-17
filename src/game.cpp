#include "game.hpp"
#include "bullet.hpp"
#include "player.hpp"

void gameFunction(sf::RenderWindow& window)
{
	std::srand(time(NULL));
	sf::Texture background_texture;
	sf::Sprite background;
	if (!background_texture.loadFromFile("content/background.png"))
	{
		std::cout << "ERROR: Cannot load background image";
	}
	background.setTexture(background_texture);
	background.setPosition(sf::Vector2f(0, 0));
	window.setFramerateLimit(60);

	// Create player
	float plr_width = 1;
	float plr_height = 1;
	float plr_x = 610;
	float plr_y = 482;
	Player player(plr_width, plr_height, plr_x, plr_y);

	// Create bullet variables
	float bullet_width = 2;
	float bullet_height = 2;
	float bullet_speed = 10;
	unsigned int reload_timer = 0;
	int cooldown = 5;
	bool bullet_firing = false;
	Bullet bullet(bullet_width, bullet_height);
	std::vector<Bullet> bullet_vector;

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				bullet_firing = true;
				reload_timer++;
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
				bullet.setPos(player.returnXPos(), player.returnYPos());
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
		}

		std::cout << bullet_vector.size() << "\n";

		player.drawTo(window);
		player.movePlayer();
		window.display();
	}
}