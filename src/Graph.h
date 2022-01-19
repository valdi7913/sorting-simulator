#pragma once

class Graph
{
	public:
		Graph(int size, sf::RenderWindow& window);
		~Graph();

		void Sort();
		void Quick();
		void Draw();
		void Shuffle();
		void Inc();
		void Dec();
		void Log();
	private:
		void Switch(int lo, int hi);
		void QuickSwitch(int* lo, int* hi);
		void QuickSort(int lo, int hi);
		int Partition(int lo, int hi);

	private:
		sf::RenderWindow* window;
		sf::Vector2i latest;
		int size;
		int values[301];
};

