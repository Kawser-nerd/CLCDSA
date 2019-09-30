#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

int MOD = 10007;

int subtract(int a, int b)
{	// a-b
	return (a-b+10007*2)%10007;
}

int process(vector<int> array)
{
	if (array.size() <= 2)
		return -2;	// conflict answer
	int i, j;
/*
	printf("Processing: ");
	for (i = 0; i < array.size(); i++)
		printf("%d ", array[i]);
	printf("\n");
*/
	// 0, 2, 4, are added
	int offset = subtract(array[2], array[1]);
	int answer = -1;
	bool passed = true;
	for (i = 4; i < array.size(); i += 2)
	{
		if (subtract(array[i], array[i-1]) != offset)
		{
			passed = false;
			break;
		}
	}
	if (passed)
	{
		if (array.size() % 2 == 0)
			answer = (array[array.size()-1] + offset) % MOD;
		else
		{
			vector<int> newArray;
			for (i = 0; i < array.size(); i += 2)
				newArray.push_back(subtract(array[i], offset));
			int curAns = process(newArray);
			answer = curAns;
		}
	}
	
	// 1, 3, 5 are added
	offset = subtract(array[1], array[0]);
	passed = true;
	int answer2 = -1;
	for (i = 3; i < array.size(); i += 2)
	{
		if (subtract(array[i], array[i-1]) != offset)
		{
			passed = false;
			break;
		}
	}
	if (passed)
	{
		if (array.size() % 2 == 1)
			answer2 = (array[array.size()-1] + offset) % MOD;
		else
		{
			vector<int> newArray;
			for (i = 0; i < array.size(); i += 2)
				newArray.push_back(array[i]);
			int curAns = process(newArray);
			answer2 = curAns;
		}
	}
	if (answer == -2 || answer2 == -2)
		return -2;
	if (answer >= 0 && answer2 >= 0 && answer != answer2)
		return -2;
	if (answer == -1 && answer2 == -1)
		return -1;
	if (answer == -1 && answer2 >= 0)
		return answer2;
	if (answer >= 0 && answer2 == -1)
		return answer;
	if (answer >= 0 && answer2 >= 0 && answer == answer2)
		return answer;
}

int main()
{
	int numCase, numN;
	scanf("%d", &numCase);
	int i, j, c;
	for (i = 0; i < numCase; i++)
	{
		scanf("%d", &numN);
		vector<int> numbers;
		for (j = 0; j < numN; j++)
		{
			scanf("%d", &c);
			numbers.push_back(c);
		}
		int result = process(numbers);
		if (result < 0)
			printf("Case #%d: UNKNOWN\n", i+1);
		else
			printf("Case #%d: %d\n", i+1, result);
	}
	return 0;
}
