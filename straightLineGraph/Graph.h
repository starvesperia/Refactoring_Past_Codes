#ifndef __GRAPH_H_
#define __GRAPH_H_

class Graph
{
private:
	int size; // Size of graph
	char **graph;

private:
	void SetAxis(); // Set X-axis, Y-axis and origin

public:
	Graph(const int size); // Constructor
	void ClearGraph();	 // Clear graph
	void StraightLine(); // Make straight line
	void Print() const;	// Print graph
	~Graph(); // Destructor
};

#endif