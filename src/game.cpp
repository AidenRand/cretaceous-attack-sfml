#include "game.hpp"
#include "player.hpp"

void gameFunction(sf::RenderWindow& window)
{

	// Create player
	float plr_width = 1;
	float plr_height = 1;
	float plr_x = 610;
	float plr_y = 482;
	Player player(plr_width, plr_height, plr_x, plr_y);
	sf::Texture background_texture;
	sf::Sprite background;
	if (!background_texture.loadFromFile("content/background.png"))
	{
		std::cout << "ERROR: Cannot load background image";
	}
	background.setTexture(background_texture);
	background.setPosition(sf::Vector2f(0, 0));
	window.setFramerateLimit(60);
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();

		window.draw(background);
		player.drawTo(window);
		player.movePlayer();
		window.display();
	}
}