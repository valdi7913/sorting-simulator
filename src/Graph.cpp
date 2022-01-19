#include "Graph.h"

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

void Graph::Sort()
{
	Draw();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (values[i] < values[j])
			{
				window -> clear();
				Switch(i, j);
				latest = sf::Vector2i(i, j);
			}
		}
	}
	latest = sf::Vector2i(-1, -1);
	Draw();
}

void Graph::Draw()
{
	for(int i = 0; i < size; i++)
	{
		sf::Vector2u windowSize = window -> getSize();
		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f(windowSize.x / size,values[i] * windowSize.y / size));
		rect.setPosition(sf::Vector2f(i * windowSize.x / size, windowSize.y - rect.getSize().y));
		//printf("Drew a square at x: %f y: %f with width %f and height %f \n", rect.getPosition().x, rect.getPosition().y, rect.getSize().x, rect.getSize().y);
		if(i == latest.x || i == latest.y)
			rect.setFillColor(sf::Color::Red);
		else rect.setFillColor(sf::Color::White);

		window -> draw(rect);
		//sf::sleep(sf::milliseconds(2));
	}
	window -> display();
}

void Graph::Switch(int i, int j)
{
	int temp = values[i];
	values[i] = values[j];
	values[j] = temp;
	Draw();
}

void Graph::Shuffle()
{
	for(int i = 0; i < size; i++)
	{
		int j = static_cast<int>(rand() % size);
		window -> clear();
		Switch(i, j);
	}
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