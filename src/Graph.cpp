#include "Graph.h"
#include <iostream>
#include <vector>
#include <algorithm>

Graph::Graph(int size, sf::RenderWindow& window)
{
	this -> size = size;
	this -> window = &window;
	this -> sorted = false;
	this -> color = sf::Color::Red;
	resetStatistics();
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
	if(sorted) return;
	QuickSort(0, size - 1);
	sorted = isSorted();
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
			rect.setFillColor(color);
		else rect.setFillColor(sf::Color::White);
		window -> draw(rect);
	}
	window -> draw(currentAlgorithm);
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
	sorted = isSorted();
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

void Graph::Merge()
{
	if(sorted) return;
	MergeSort(0, size - 1);
	sorted = isSorted();
}

void Graph::MergeSort(int lo, int hi)
{
	if(hi <= lo) return;
	int mid = static_cast<int>(0.5 * (hi + lo));
	MergeSort(lo, mid);
	MergeSort(mid + 1, hi);
	Merge(lo, mid, hi);
}

void Graph::Merge(int lo, int mid, int hi)
{
	int i = lo;
	int j = mid + 1;
	//Copy values into auxillary
	for (int k = lo; k <= hi; k++)
		aux[k] = values[k];
	for (int k = lo; k <= hi; k++)
	{
		if(i > mid) values[k] = aux[j++];
		else if(j > hi) values[k] = aux[i++];
		else if(aux[j] < aux[i]) values[k] = aux[j++];
		else values[k] = aux[i++];
		window -> clear();
		latest = sf::Vector2i(i,  j);
		Draw();
	}
}

void Graph::Shell()
{
	int N = size;
	int h = 1;
	while(h < N/3) h = 3*h + 1;
	while(h >= 1)
	{
		for(int i = h; i < N; i++)
		{
			for (int j = i; j >= h && values[j] < values[(j - h)]; j -= h) Switch(j, j-h);
		}
		h = h/3;
	}
}

void Graph::Bucket()
{
	int n = 20;
	 // 1) Create n empty buckets
    std::vector<float> b[20];

    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * values[i]; // Index in bucket
        b[bi].push_back(values[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < static_cast<int>(b[i].size()); j++)
            values[index++] = b[i][j];
}

void Graph::Selection()
{
	int n = size;
	for(int i = 0; i < n; i++)
	{
		int min = i;
		for(int j = i + 1; j < n; j++)
		{
			if(values[j] < values[min]) min = j;
			Switch(i, min);
		}
	}
}

void Graph::Insertion()
{
	int N = size;
	for(int i = 1; i < N; i ++)
	{
		for(int j = i; j > 0 && values[j] < values[j - 1]; j--)
		{
			Switch(j, j-1);
		}
	}
}

bool Graph::isSorted()
{
	color = sf::Color::Green;
	for(int i = 1; i < size; i++)
	{
		latest = sf::Vector2i(i, i-1);
		Draw();
		if(values[i-1] > values[i])
			{
				color = sf::Color::Red;
				return false;
			}
		sf::sleep(sf::milliseconds(10));
	}
	color = sf::Color::Red;
	latest = sf::Vector2i(-1, -1);
	Draw();
	return true;

}

void Graph::SetText(sf::String text)
{
	algorithmName = text;
}

void Graph::resetStatistics()
{
	currentAlgorithm.setString(algorithmName);
	currentAlgorithm.setPosition(500, 500);
	algorithmName = "Select a sorting algorithm";
}