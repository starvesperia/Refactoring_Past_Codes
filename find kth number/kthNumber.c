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

int main()
{
	FILE *inFile;
	int i;
	int numCases, inputData;

	inFile = fopen("input.txt", "r");
	if(inFile == NULL) exit(1);
	fscanf(inFile, "%d", &numCases);

	for(i=0; i<numCases; i++)
	{
		fscanf(inFile, "%d", &inputData);
		(inputData < 10 ? printf("%d\n", inputData) : printf("%d\n", findK(inputData)));
	}
	fclose(inFile);
	return 0;
}


int findK(int k)
{
	int width = 20, height = 9; // 가상의 표의 크기.
	int digit, position, row, column;
	int kTemp, i;
	int kthNumber;
	k = k - 9; // 1~9 제외

	/* k번째수가 포함되는 숫자가 몇자리 수인지 알아보는 과정 */
	do							// 자리수를 넘어갈 경우 다음 표를 찾는다
	{							// 표는 해당 자리수의 처음숫자부터 마지막 숫자까지 늘어놓은 표이다.
		kTemp = k;				// 예를 들면 두자리수 표라면 10부터 99까지 늘어놓은 표이다.
		k -= (width * height);	// 각 행은 10의 자리수로 끊는다. (10~19, 20~29 ...)
		width += 10;			// 열의 수는 두자리 수일 경우 20, 세자리 수일 경우 30... 자리수가 늘어날때마다 10씩 증가한다.
		height *= 10;			// 행의 수는 두자리 수일 경우 9, 세자리 수일경우 90... 자리수가 늘어날때마다 10배로 증가한다.
	}
	while(k > 0);
	k = kTemp;					// 이 단계에서 이전 자리수를 모두 제외한 상태에서의 k값이 저장된다.
	width -= 10;					// 마지막에 한번 더 10이 더해진 것을 되돌린다.

	digit = width / 10;			// digit에 위에서 몇자리 수인지 구한 것을 대입. 각 열에는 10개의 수가 있으므로 10으로 나눠준다.
	position = k % digit;		// k번쨰 수가 포함된 숫자에서 k번째숫자의 위치-왼쪽에서부터 센다 (ex. 104 에서 k번째수가 1 이라면 position은 1, 4라면 position은3)
	column = k % (digit * 10);	// k번째 수가 있는 가상의 열. 1열부터 시작한다고 가정.
	row = k / (digit * 10);		// k번째 수가 있는 가상의 행. 편의상 0행부터 시작하는 것으로 가정

	if(column == 0)				// 마지막 열의 경우는 10으로 나누어 떨어져서 다음열로 넘어가게 되어있으므로.
	{							// 행을 하나 올리고 열을 마지막열로 맞춰준다.
		column = digit * 10;      
		row--;
	}

	if(position == 0)		// k번째 숫자가 포함된 숫자에서 k번째 숫자의 위치가 마지막 자리(1의자리)일 경우 예) 103에서 3이 k번째일때
	{
		if(column != 0)		// k번째 숫자가 포함된 숫자에서 k번째 숫자의 위치가 마지막 자리(1의자리)일 경우 예) 103에서 3이 k번째일때
			kthNumber = (column / digit) - 1;
		else				// 마지막 자리의 마지막 열인경우 숫자는 항상 9이다.
			kthNumber = 9;
	}
	else if(position == 1)	// k번째 숫자가 포함된 숫자에서 k번째 숫자의 위치가 첫번째 자리일 경우
		kthNumber = ( ( row / exponentation(10, (digit-2)) ) % 9 ) + 1;

	else					// k번째 숫자가 포함된 숫자에서 k번째 숫자의 위치가 중간부분일 경우
	{
		for(i = (digit - (position + 1)); i > 0; i--) // 열의 값을 중간에서 가장 오른쪽에 있을때부터 왼쪽으로 한번씩 갈때마다
			row /= 10;								  // 10으로 나누어 준다.(가장 오른쪽부터 1의자리, 10의자리, 100의자리...)
		row %= 10;									  // 그 수의 나머지는 k번째 수가 된다.
		kthNumber = row;
	}

	return kthNumber;
}

