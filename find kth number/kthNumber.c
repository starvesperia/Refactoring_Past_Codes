/*
Kth number
*/

#include <stdio.h>
#include <stdlib.h>


int findK(int k);

int exponentation(int base, int exp)    //편의상 만든 제곱함수
{
	int result = 1;

	while(exp--)
		result *= base;

	return result;
}

void main()
{
	FILE *in_file;
	int i;
	int no_cases, inputData;

	in_file = fopen("input.txt", "r");
	if(in_file == NULL) exit(1);

	fscanf(in_file, "%d", &no_cases);

	for(i=0; i<no_cases; i++)
	{
		fscanf(in_file, "%d", &inputData);
		(inputData < 10 ? printf("%d\n", inputData) : printf("%d\n", findK(inputData)));
	}
	fclose(in_file);
}


int findK(int k)
{
	int x = 20, y = 9; // 가상의 표의 크기
	int z, temp, position, row, column;
	int kthNumber;

	// k번째수가 포함되는 숫자가 몇자리 수인지 알아보는 과정	
	k = k - 9; // 1~9 제외
	do						// 자리수를 넘어갈 경우 다음 표를 찾는다
	{						// 표는 해당 자리수의 처음숫자부터 마지막 숫자까지 늘어놓은 표이다.
		temp = k;			// 예를 들면 두자리수 표라면 10부터 99까지 늘어놓은 표이다.
		k = k - (x * y);		// 각 행은 10의 자리수로 끊는다.
		x = (x + 10);
		y = y * 10;
	}
	while(k > 0);

	k = temp; 

	z = (x / 10) - 1;		// z에 위에서 몇자리 수인지 구한 것을 대입

	position = k % z;		// k번쨰 수가 포함된 숫자에서 k번째숫자의 위치-왼쪽에서부터 센다 (ex. 104 에서 k번째수가 1 이라면 position은 1, 4라면 position은3)

	column = k % (z * 10);	// 가상의 열  (ex. z가 3일 경우 100에서 109까지 나열하면 30개의 열이 생긴다)
	row = k / (z * 10);		// 가상의 행  (ex. z가 2일 경우 가로20 세로9 (10~90)의 가상의 표를 만들 수 있다)

	if(column == 0)			// 마지막 열의 경우는 10으로 나누어 떨어져서 다음열로 넘어가게 되어있으므로 재 설정해준다.
	{
		column = z * 10;      
		row = row - 1;
	}

	if(position == 0 && column != 0)		// k번째 숫자가 포함된 숫자에서 k번째 숫자의 위치가 마지막 자리(1의자리)일 경우 예) 103에서 3이 k번째일때
		kthNumber = (column / z) - 1;

	else if(position == 0 && column == 0)	// 위 조건으로는 마지막 자리중 열의 마지막인 경우가 안되므로 재설정
		kthNumber = 9;       

	else if(position == 1)					// k번째 숫자가 포함된 숫자에서 k번째 숫자의 위치가 첫번째 자리일 경우
		kthNumber = ((row / exponentation(10, (z-2))) % 9) +1;

	else									// k번째 숫자가 포함된 숫자에서 k번째 숫자의 위치가 중간부분일 경우
	{
		temp = (z - (position + 1));
		while(temp > 0)						// 중간에서 가장 오른쪽에 있을때부터 왼쪽으로 한번씩 갈때마다
		{									// 10으로 나누어 주어야 10으로 나누었을때 나머지가 k번째 수가된다.
			row = row / 10;
			temp--;
		}
		row = row % 10;
		kthNumber = row;
	}

	return kthNumber;
}

