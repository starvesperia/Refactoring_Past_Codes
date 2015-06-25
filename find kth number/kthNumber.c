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

	if(a<10)       // k��°���� ���ԵǴ� ���ڰ� ���ڸ� ������ �˾ƺ��� ����
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

		z = (x/10)-1;      //z�� ������ ���ڸ� ������ ���� ���� ����

		position = a % z;     //k���� ���� ���Ե� ���ڿ��� k��°������ ��ġ-���ʿ������� ���� (ex. 104 ���� k��°���� 1 �̶�� position�� 1, 4��� position��3)

		column = a % (z*10);  //������ ��  (ex. z�� 3�� ��� 100���� 109���� �����ϸ� 30���� ���� �����)
		row = a / (z*10);     //������ ��  (ex. z�� 2�� ��� ����20 ����9 (10~90)�� ������ ǥ�� ���� �� �ִ�)

		if(column == 0)      //������ ���� ���� 10���� ������ �������� �������� �Ѿ�� �Ǿ������Ƿ� �� �������ش�.
		{
			column = z*10;      
			row = row - 1;
		}

		if(position == 0 && column != 0)  //k��° ���ڰ� ���Ե� ���ڿ��� k��° ������ ��ġ�� ������ �ڸ�(1���ڸ�)�� ���
			k = (column / z) - 1;
		else if(position == 0 && column == 0) //�� �������δ� ������ �ڸ��� ���� �������� ��찡 �ȵǹǷ� �缳��
			k = 9;       

		else if(position == 1)    //k��° ���ڰ� ���Ե� ���ڿ��� k��° ������ ��ġ�� ù��° �ڸ��� ���
		{ 
			k = ((row / square(10, (z-2))) % 9) +1;
		}

		else        //k��° ���ڰ� ���Ե� ���ڿ��� k��° ������ ��ġ�� �߰��κ��� ���
		{
			temp = (z-(position + 1));
			while(temp > 0)     //�߰����� ���� �����ʿ� ���������� �������� �ѹ��� �������� 10���� ������ �־�� 10���� ���������� �������� k��° �����ȴ�.
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

int square(int a, int b)    //���ǻ� ���� �����Լ�
{
	int i;
	int c = 1;

	for(i = 1; i <= b; i++)
	{
		c *= a;
	}

	return c;
}