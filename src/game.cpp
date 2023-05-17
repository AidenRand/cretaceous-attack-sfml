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
	std::vector<Bullet> bullet_vector;
	float bullet_width = 5;
	float bullet_height = 5;
	float bullet_speed = 2;
	;
	Bullet bullet(bullet_width, bullet_height);
	bool bullet_firing = false;
	unsigned int reload_timer = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				bullet_firing = true;
				reload_timer++;
			}
		}
		window.clear();
		window.draw(background);

		if (reload_timer == 0)
		{
			if (bullet_firing)
			{
				bullet.fireBullet(player, bullet_speed);
				bullet.setPos(player.returnXPos(), player.returnYPos());
				bullet_firing = false;
				reload_timer += 5;
				bullet_vector.push_back(bullet);
			}
		}
		else
		{
			reload_timer--;
		}

		for (long unsigned int i = 0; i < bullet_vector.size(); i++)
		{
			bullet_vector[i].drawTo(window);
		}

		std::cout << bullet_vector.size() << "\n";

		player.drawTo(window);
		player.movePlayer();
		window.display();
	}
}