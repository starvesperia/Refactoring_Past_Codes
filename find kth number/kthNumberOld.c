/*
Kth number
*/

#include <stdio.h>
#include <stdlib.h>

int findK(int b);
int square(int a, int c);

void main()
{
	FILE *in_file;
	int i;
	int no_cases, no_data;
	int k;

	in_file = fopen("input.txt", "r");
	if(in_file == NULL) exit(1);

	fscanf(in_file, "%d", &no_cases);

	for(i=0; i<no_cases; i++)
	{
		fscanf(in_file, "%d", &no_data);

		k = findK(no_data);
		printf("%d\n", k);
	}
	fclose(in_file);
}


int findK(int a)
{
	int x = 20;
	int y = 9;
	int z, temp, position, row, column;
	int k;

	if(a<10)       // k번째수가 포함되는 숫자가 몇자리 수인지 알아보는 과정
	{
		k = a;
		return k;
	}

	else
	{
		a = a-9;
		do
		{
			temp = a;
			a= a-(x*y);
			x=(x+10);
			y=y*10;
		}
		while(a>0);      

		a = temp; 

		z = (x/10)-1;      //z에 위에서 몇자리 수인지 구한 것을 대입

		position = a % z;     //k번쨰 수가 포함된 숫자에서 k번째숫자의 위치-왼쪽에서부터 센다 (ex. 104 에서 k번째수가 1 이라면 position은 1, 4라면 position은3)

		column = a % (z*10);  //가상의 열  (ex. z가 3일 경우 100에서 109까지 나열하면 30개의 열이 생긴다)
		row = a / (z*10);     //가상의 행  (ex. z가 2일 경우 가로20 세로9 (10~90)의 가상의 표를 만들 수 있다)

		if(column == 0)      //마지막 열의 경우는 10으로 나누어 떨어져서 다음열로 넘어가게 되어있으므로 재 설정해준다.
		{
			column = z*10;      
			row = row - 1;
		}

		if(position == 0 && column != 0)  //k번째 숫자가 포함된 숫자에서 k번째 숫자의 위치가 마지막 자리(1의자리)일 경우
			k = (column / z) - 1;
		else if(position == 0 && column == 0) //위 조건으로는 마지막 자리중 열의 마지막인 경우가 안되므로 재설정
			k = 9;       

		else if(position == 1)    //k번째 숫자가 포함된 숫자에서 k번째 숫자의 위치가 첫번째 자리일 경우
		{ 
			k = ((row / square(10, (z-2))) % 9) +1;
		}

		else        //k번째 숫자가 포함된 숫자에서 k번째 숫자의 위치가 중간부분일 경우
		{
			temp = (z-(position + 1));
			while(temp > 0)     //중간에서 가장 오른쪽에 있을때부터 왼쪽으로 한번씩 갈때마다 10으로 나누어 주어야 10으로 나누었을때 나머지가 k번째 수가된다.
			{
				row = row / 10;
				temp--;
			}

			row = row % 10;
			k = row;
		}

		return k;
	}
}

int square(int a, int b)    //편의상 만든 제곱함수
{
	int i;
	int c = 1;

	for(i = 1; i <= b; i++)
	{
		c *= a;
	}

	return c;
}