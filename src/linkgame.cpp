#include "Player.h"
#include <Platform/IPlatform.hpp>
#include <iostream>

int game()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "link", sf::Style::Close | sf::Style::Resize);

	sf::Texture texture;
	texture.loadFromFile("./src/link.png");

	Player player(&texture, sf::Vector2u(10, 8), 0.3f, 200.0f);

	sf::Clock clock;
	float deltaTime = 0.0f;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event evt;
		while (window.pollEvent(evt))
		{
			if (evt.type == sf::Event::Closed)
				window.close();
			else if (evt.type == sf::Event::Resized)
				printf("Window rezied to %d x %d\n", evt.size.width, evt.size.height);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		player.Update(deltaTime);
		window.clear();
		player.Draw(window);
		window.display();
	}
	return 0;
}
