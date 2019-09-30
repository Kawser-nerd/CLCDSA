#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


#define returnIfCan()  { /*fprintf(stderr, "curIn = %d, curBorder = %d, curSide = %d, k = %d\n", curIn, curBorder, curSide, k); */if (curBorder + curIn >= k) return curBorder;}

int solve()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if (n > m)
		swap(n, m);

	if (n <= 2 || k < 5)
		return k;

	int curIn = 1;
	int curBorder = 4;
	int curSide = 2;

	while (2 * curSide + 1 <= n)
	{
		returnIfCan();

		curBorder++;
		curIn += curSide - 2;

		returnIfCan();

		curBorder++;
		curIn += curSide - 1;

		returnIfCan();

		curBorder++;
		curIn += curSide - 1;

		returnIfCan();
		
		curBorder++;
		curIn += curSide;

		returnIfCan();
		curSide++;
	}
	vector <int> hasUp;
	if (n % 2 == 0)
	{
		returnIfCan();

		curBorder++;
		curIn += curSide - 2;

		returnIfCan();

		curBorder++;
		curIn += curSide - 1;

		returnIfCan();
	}
	if (n % 2 == 1)
	{
		for (int curW = 2 * curSide - 1; curW < m; curW++)
		{
			returnIfCan();
			
			curIn += curSide - 2;
			curBorder++;

			returnIfCan();

			curIn += curSide - 1;
			curBorder++;

			returnIfCan();
		}
	}
	else
	{
		for (int curW = 2 * curSide; curW < m; curW++)
		{
			returnIfCan();

			curIn += curSide - 1;
			curBorder++;

			returnIfCan();

			curIn += curSide - 1;
			curBorder++;

			returnIfCan();
		}
	}

	if (n % 2 == 0)
	{
		hasUp.push_back(curSide);
		hasUp.push_back(curSide);
		hasUp.push_back(curSide - 1);
		hasUp.push_back(curSide - 1);
	}
	else
	{
		hasUp.push_back(curSide - 1);
		hasUp.push_back(curSide - 1);
		hasUp.push_back(curSide - 1);
		hasUp.push_back(curSide - 1);
	}
	while (hasUp[0] != 0)
	{
		returnIfCan();
		curBorder++;
		curIn += hasUp[0] - 1;
		hasUp[0]--;

		sort(hasUp.begin(), hasUp.end() );
		reverse(hasUp.begin(), hasUp.end() );
	}
	returnIfCan();
	fprintf(stderr, "An error accured\n");
	return -1;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		fprintf(stderr, "Case #%d: ", i);
		printf("Case #%d: ", i);
		printf("%d\n", solve() );
		fprintf(stderr, "OK\n");
	}



	return 0;
}