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
	float background_x = 0;
	float background_y = -120;
	background.setPosition(sf::Vector2f(background_x, background_y));

	// End game text variables
	std::string end_text_string = "Press space \t\t\t\t to play again";
	float end_text_x = 190;
	float end_text_y = 500;

	// Score variables
	int score = 0;
	float score_x = 60;
	float score_y = 50;

	// Lives left variables
	int lives_left = 5;
	float lives_x = 1180;
	float lives_y = 50;

	// Create player
	float plr_width = 1;
	float plr_height = 1;
	float plr_x = 600;
	float plr_y = 482;
	Player player(plr_width, plr_height, plr_x, plr_y);

	// Bullet variables
	float bullet_width = 5;
	float bullet_height = 5;
	float bullet_x = 640;
	float bullet_y = 505;
	int bullet_speed = 40;
	int cooldown = 10;
	unsigned int reload_timer = 0;
	bool bullet_firing = false;
	bool bullet_dead = false;
	std::vector<Bullet> bullet_vector;
	Bullet bullet(bullet_width, bullet_height);

	// Dinosaur variables
	float dino_width = 128;
	float dino_height = 64;
	int dino_speed = 10;
	bool dino_dead = false;

	// Create dinosaurs
	sf::Texture bottom_dinosaur_texture;
	if (!bottom_dinosaur_texture.loadFromFile("content/bottom-dinosaur.png"))
	{
		std::cout << "ERROR: Cannot load bottom dinosaur texture";
	}
	Dinosaur dinosaur(dino_width, dino_height);
	dinosaur.spawnDinosaur(screen_width, screen_height, dino_height, dino_width);

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
			dinosaur.moveDinosaur(dino_speed);
			dinosaur.drawTo(window);
		}
		dinosaur.killDinosaur(dino_dead, player, lives_left);

		// If dino_dead == true, reset dinosaur
		if (dino_dead)
		{
			dinosaur.spawnDinosaur(screen_width, screen_height, dino_height, dino_width);
			dino_dead = false;
		}

		player.drawTo(window);
		player.changePlayerTexture();

		// Create score and lives left
		std::string font_file = "content/8_bit_party.ttf";
		Logic logic(font_file);
		logic.makeScore(score, score_x, score_y);
		logic.drawScore(window);
		logic.makeLives(lives_left, lives_x, lives_y);
		logic.drawLives(window);

		// If no lives left, end game
		if (lives_left == 0)
		{
			logic.makeEndText(end_text_string, end_text_x, end_text_y);
			logic.endGame(window, score, lives_left, dino_speed);
		}

		window.display();
	}
}