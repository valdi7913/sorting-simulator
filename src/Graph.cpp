#include "Graph.h"
#include <iostream>

Graph::Graph(int size, sf::RenderWindow& window)
{
	this -> size = size;
	this -> window = &window;
	latest = sf::Vector2i(-1, -1);
	for (int i = 0; i < size; i++)
	{
		values[i] = size - i;
	}
}

Graph::~Graph()
{

}

void Graph::Log()
{
	for (int i = 0; i < size; i++)
		std::cout << values[i];
	sf::sleep(sf::milliseconds(100));
}

void Graph::Sort()
{
	Draw();
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (values[i] > values[j])
			{
				Switch(i,j);
			}
		}
	}
	latest = sf::Vector2i(-1, -1);
	window -> clear();
	Draw();
}

void Graph::Switch(int lo, int hi)
{
	int temp = this -> values[lo];
	values[lo] = values[hi];
	values[hi] = temp;
	latest = sf::Vector2i(lo, hi);
	window -> clear();
	Draw();
}

void Graph::Quick()
{
	Shuffle();
	QuickSort(0, size - 1);
}

void Graph::QuickSort(int lo, int hi)
{
	if(hi <= lo) return;
	int j = Partition(lo, hi);
	QuickSort(lo, j - 1);
	QuickSort(j + 1, hi);
}

int Graph::Partition(int lo, int hi)
{

    int pivot = values[hi];    // pivot
    int i = (lo - 1);  // Index of smaller element

    for (int j = lo; j <= hi- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (values[j] <= pivot)
        {
            i++;
            QuickSwitch(&values[i], &values[j]);
        }
    }
    QuickSwitch(&values[i + 1], &values[hi]);
    return (i + 1);

}

void Graph::Draw()
{
	for(int i = 0; i <= size; i++)
	{
		float margin = 4.0f;
		sf::Vector2u windowSize = window -> getSize();
		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f(windowSize.x / size - margin, ((values[i] - 1) * windowSize.y / size)));
		rect.setPosition(sf::Vector2f(i * windowSize.x / size + margin, windowSize.y - rect.getSize().y));
		//printf("Drew a square at x: %f y: %f with width %f and height %f \n", rect.getPosition().x, rect.getPosition().y, rect.getSize().x, rect.getSize().y);
		if(i == latest.x || i == latest.y)
			rect.setFillColor(sf::Color::Red);
		else rect.setFillColor(sf::Color::White);
		window -> draw(rect);
	}
	window -> display();
}

void Graph::QuickSwitch(int* i, int* j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
	latest = sf::Vector2i(*i, *j);
	window -> clear();
	Draw();
}

void Graph::Shuffle()
{
	for(int i = 0; i < size; i++)
	{
		int j = static_cast<int>(rand() % size);
		window -> clear();
		QuickSwitch(&values[i], &values[j]);
	}
	window -> clear();
	Draw();
}

void Graph::Inc()
{
	size++;
	values[size] = size;
	Shuffle();
}

void Graph::Dec()
{
	for(int i = 0; i < size; i++)
		if(values[i] == size)
			values[i] = 0;
	size--;
	Shuffle();
}