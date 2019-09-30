#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int MAX_N = 1000 + 100;

int n, statCnt;
int minA, maxA, minB, maxB;

struct Stat {
	int a, b;
	bool val;
} stats[MAX_N];

void add(int a, int b, bool isBird)
{
	if (isBird)
	{
		minA = min(minA, a);
		minB = min(minB, b);
		maxA = max(maxA, a);
		maxB = max(maxB, b);
		return;
	}
	stats[statCnt].a = a;
	stats[statCnt].b = b;
	stats[statCnt].val = isBird;
	++statCnt;
}

bool canBeBird(int a, int b)
{
	int preMinA = minA, preMinB = minB, preMaxA = maxA, preMaxB = maxB;

	minA = min(minA, a);
	minB = min(minB, b);
	maxA = max(maxA, a);
	maxB = max(maxB, b);

	bool result = true;
	for (int i = 0; i < statCnt; ++i)
	{
		if (minA <= stats[i].a && stats[i].a <= maxA && minB <= stats[i].b && stats[i].b <= maxB)
		{
			result = false;
			break;
		}
	}

	minA = preMinA; minB = preMinB; maxA = preMaxA; maxB = preMaxB;
	return result;
}

int solve(int a, int b)
{
	if (minA <= a && a <= maxA && minB <= b && b <= maxB)
		return 1; // IS BIRD
	return canBeBird(a, b) ? -1 : 0;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int caseNo = 1; caseNo <= cases; ++caseNo)
	{
		scanf("%d", &n);
		statCnt = 0;
		minA = INT_MAX, maxA = INT_MIN;
		minB = INT_MAX, maxB = INT_MIN;
		for (int i = 0, a, b; i < n; ++i)
		{
			char str[20];
			scanf("%d %d %s", &a, &b, str);
			add(a, b, str[0] == 'B');
			if (str[0] == 'N')
				scanf("%s", str);
		}
		printf("Case #%d:\n", caseNo);
		int queryCnt;
		scanf("%d", &queryCnt);
		for (int i = 0, a, b; i < queryCnt; ++i)
		{
			scanf("%d %d", &a, &b);
			int result = solve( a, b );
			printf("%s\n", result == 1 ? "BIRD" :
				result == 0 ? "NOT BIRD" : "UNKNOWN");
		}
	}
	return 0;
}



