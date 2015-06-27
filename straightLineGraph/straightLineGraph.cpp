/*
problem
직선 그래프 출력하기
*/

/*
컴퓨터 공학부 2학년
20103343 
박형순
*/

#include <iostream>
#include <fstream>
#include "Graph.h"

void main ()
{
	std::ifstream inStream;
	int numTestCases;

	inStream. open("input.txt"); /* open input file*/
	if(inStream.fail())
	{
		std::cerr << "Input file opening failed.\n";
		exit(1);
	}

	inStream >> numTestCases;	/* read the number of test cases */
	for (int i=0; i<numTestCases; i++)
	{
		int sizeOfGraph;
		inStream >> sizeOfGraph;
		
		Graph graph(sizeOfGraph);
		graph.StraightLine();
		graph.Print();
	}
	inStream.close();	/* close input file */
}
