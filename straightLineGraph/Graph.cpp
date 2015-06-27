#include <iostream>
#include "Graph.h"

Graph::Graph(const int size) : size(size)
{
	graph = new char*[size];
	for(int i = 0; i < this->size; i++)
		graph[i] = new char[size];
	ClearGraph();
}

Graph::~Graph()
{
	delete []*graph;
	delete []graph;
}

void Graph::ClearGraph()
{
	for(int i = 0; i < this->size; i++)
		for(int j = 0; j < this->size; j++)
			graph[i][j] = '.';
	SetAxis();
}

void Graph::SetAxis()
{
	int i;	
	for(i = 0; i < this->size; i++) // Set X-axis
		graph[size/2][i] = '+';
	for(i = 0; i < this->size; i++) // Set Y-axis
		graph[i][size/2] = 'I';
	graph[size/2][size/2] = 'O';	// Set Origin
}

void Graph::StraightLine()
{
	int i;
	for(i = 0; i < size/2; i++)
		graph[i][(size-1) - i] = '*';
	for(i = (size/2)+1; i < size; i++)
		graph[i][(size-1) - i] = '*';
}

void Graph::Print() const
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
			std::cout << graph[i][j];
		std::cout << std::endl;
	}
}