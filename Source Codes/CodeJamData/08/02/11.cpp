#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;

int trainAS[110];
int trainAE[110];
int trainBS[110];
int trainBE[110];

int needTrain(VI arrive, VI leave)
{
	int count = 0;
	int availTrain = 0;
	int aSize = arrive.size(), lSize = leave.size();
	int aPos = 0, lPos = 0;
//	printf("\nDebug %d %d\n", aSize, lSize);
	while (aPos < aSize || lPos < lSize)
	{
		if (lPos == lSize || (aPos < aSize && arrive[aPos] <= leave[lPos]))
		{
			aPos++;
			availTrain++;
		}
		else
		{
			lPos++;
			if (availTrain == 0)
				count++;
			else
				availTrain--;
		}
	}
	return count;
}

int main()
{
	int numCase;
	int turnTime, stA, stB;
	scanf("%d", &numCase);
	int i, j;
	for (i = 0; i < numCase; i++)
	{
		scanf("%d %d %d", &turnTime, &stA, &stB);
		int h, m;
		for (j = 0; j < stA; j++)
		{
			scanf("%d:%d", &h, &m);
			trainAS[j] = h*60+m;
			scanf("%d:%d", &h, &m);
			trainAE[j] = h*60+m;
		}
		for (j = 0; j < stB; j++)
		{
			scanf("%d:%d", &h, &m);
			trainBS[j] = h*60+m;
			scanf("%d:%d", &h, &m);
			trainBE[j] = h*60+m;
		}
		VI arrive, leave;
		for (j = 0; j < stB; j++)
			arrive.push_back(trainBE[j] + turnTime);
		for (j = 0; j < stA; j++)
			leave.push_back(trainAS[j]);
		sort(arrive.begin(), arrive.end());
		sort(leave.begin(), leave.end());
		printf("Case #%d: %d ", i+1, needTrain(arrive, leave));
		arrive.clear();
		leave.clear();
		for (j = 0; j < stA; j++)
			arrive.push_back(trainAE[j] + turnTime);
		for (j = 0; j < stB; j++)
			leave.push_back(trainBS[j]);
		sort(arrive.begin(), arrive.end());
		sort(leave.begin(), leave.end());
		printf("%d\n", needTrain(arrive, leave));
	}
	return 0;
}
