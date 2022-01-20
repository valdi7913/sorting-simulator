#include <Platform/IPlatform.hpp>
#include <iostream>
#include "Graph.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "sorting-test", sf::Style::Close | sf::Style::Resize | sf::Style::Titlebar);
	Graph graph(100, window);
	graph.Draw();

	while (window.isOpen())
	{
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
			graph.Bucket();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
			graph.Shell();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			graph.Log();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			graph.Merge();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
			graph.Inc();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			graph.Dec();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			graph.Quick();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			graph.Shuffle();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			graph.Selection();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			graph.Insertion();
	}
	return 0;
}
