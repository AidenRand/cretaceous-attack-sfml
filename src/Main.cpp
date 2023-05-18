#include "game.hpp"
#include <SFML/Graphics.hpp>
int main()
{
	// Create window
	float window_width = 1280;
	float window_height = 1024;
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Cretaceous Attack");
	gameFunction(window, window_width, window_height);
}