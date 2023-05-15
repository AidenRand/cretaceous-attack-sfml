#include "game.hpp"
#include "player.hpp"

void gameFunction(sf::RenderWindow& window)
{

	float plr_width = 30;
	float plr_height = 30;
	float plr_x = 610;
	float plr_y = 482;
	Player player(plr_width, plr_height, plr_x, plr_y);
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

		player.drawTo(window);
		window.display();
	}
}