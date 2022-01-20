#pragma once

class Graph
{
	public:
		Graph(int size, sf::RenderWindow& window);
		~Graph();

		void Bucket();
		void Selection();
		void Insertion();
		void Sort();
		void Shell();
		void Quick();
		void Merge();
		void Draw();
		void Shuffle();
		void Inc();
		void Dec();
		void Log();
		void SetText(sf::String text);
	private:
		void Switch(int lo, int hi);
		void QuickSwitch(int* lo, int* hi);
		void QuickSort(int lo, int hi);
		void MergeSort(int lo, int hi);
		void Merge(int lo, int mid, int hi);
		int Partition(int lo, int hi);
		bool isSorted();
		void resetStatistics();

	public:
		bool sorted;

	private:
		sf::RenderWindow* window;
		sf::Vector2i latest;
		sf::Color color;
		sf::Text currentAlgorithm;
		sf::Text comparisons;
		sf::Text switchCount;
		//int comps;
		//int switches;
		sf::String algorithmName;
		int size;
		int values[301];
		int aux[301];
};

