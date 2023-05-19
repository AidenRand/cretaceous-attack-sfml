#include "game.hpp"
#include <SFML/Graphics.hpp>
int main()
{
	// Create window
	float screen_width = 1280;
	float screen_height = 1024;
	sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "Cretaceous Attack");
	gameFunction(window, screen_width, screen_height);
}