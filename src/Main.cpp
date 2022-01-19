#include <Platform/IPlatform.hpp>
#include <iostream>
#include "Graph.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "sorting-test", sf::Style::Close | sf::Style::Resize);

	Graph graph(300, window);
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			graph.Draw();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			graph.Log();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			graph.Sort();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			graph.Quick();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			graph.Shuffle();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
			graph.Inc();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			graph.Dec();
	}
	return 0;
}
