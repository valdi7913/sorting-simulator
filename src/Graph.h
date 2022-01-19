#pragma once

class Graph
{
	public:
		Graph(int size, sf::RenderWindow& window);
		~Graph();

		void Sort();
		void Draw();
		void Shuffle();
		void Inc();
		void Dec();
	private:
		void Switch(int i, int j);

	private:
		sf::RenderWindow* window;
		sf::Vector2i latest;
		int size;
		int values[100];
};