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
using namespace std;
void printStGraph(int s);

void main ()
{
	ifstream inStream;
	int numTestCases;

	inStream. open("input.txt"); /* open input file*/
	if(inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}

	inStream >> numTestCases;	/* read the number of test cases */
	for (int i=0; i<numTestCases; i++)
	{
		int sizeOfGraph;
		inStream >> sizeOfGraph;
		printStGraph(sizeOfGraph);
	}
	inStream.close();	/* close input file */
}

void printStGraph(int s)
{
	// the 1st, 2nd quadrant 
	int row=1;
	for(int rowCount=0; rowCount<s/2; rowCount++)
	{
		for(int dot=0; dot<s/2; dot++)
			cout<<".";
		cout<<"I";	//Y-axis
		for(int dot=0; dot<(s/2)-row; dot++)
			cout<<".";
		cout<<"*";
		for(int dot=0; dot<rowCount; dot++)
			cout<<".";
		row++;
		cout<<endl;
	}

	// X-axis 
	for(int col=0; col<s/2; col++)
		cout<<"+";
	cout<<"O";
	for(int col=0; col<s/2; col++)
		cout<<"+";
	cout<<endl;
	
	// the 3rd, 4th quadrant
	row=1;
	for(int rowCount=0; rowCount<s/2; rowCount++)
	{
		for(int dot=0; dot<(s/2)-row; dot++)
			cout<<".";
		cout<<"*";
		for(int dot=0; dot<rowCount; dot++)
			cout<<".";
		cout<<"I";	// Y-axis
		for(int dot=0; dot<s/2; dot++)
			cout<<".";
		row++;
		cout<<endl;
	}
}