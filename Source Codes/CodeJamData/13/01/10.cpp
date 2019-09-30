#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <string>
#include <ctime>

using namespace std;

#define rep(x, y, z) for(int x = (y), end##x = (z); x < end##x; x++)
#define all(x) (x).begin(),(x).end()

#ifdef LOCAL_DEBUG

#define DebugPrint(...) fprintf(stderr, __VA_ARGS__);

#else

#define DebugPrint(...)

#endif

typedef long long ll;
typedef pair<int, int> pii;

void test(int testNum);

int main()
{
	//
#ifdef LOCAL_DEBUG

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

#else

	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

#endif

	clock_t cl = clock();

	int tc;
	scanf("%d", &tc);

	rep(i, 0, tc)
		test(i+1);

#ifdef LOCAL_DEBUG

	fprintf(stderr, "\nTime used: %lf\n", (clock() - cl) / (double)CLOCKS_PER_SEC);

#endif

	return 0;
}

void test(int testNum)
{
	printf("Case #%d: ", testNum);

	int board[4][4];

	bool notFinished = 0;
	rep(i, 0, 4)
	{
		rep(j, 0, 4)
		{
			char c;
			scanf(" %c", &c);
			if (tolower(c) == 't')
				board[i][j] = 0;
			else if (tolower(c) == 'x')
				board[i][j] = 1;
			else if (tolower(c) == 'o')
				board[i][j] = 2;
			else
			{
				board[i][j] = 15;
				notFinished = 1;
			}
		}
	}

	bool hasX = 0, hasO = 0;
	rep(i, 0, 4)
	{
		int cur[2] = {0, 0};
		rep(j, 0, 4)
		{
			cur[0] |= board[i][j];
			cur[1] |= board[j][i];
		}
		rep(j, 0, 2)
		{
			if (cur[j] == 1)
				hasX = 1;
			else if (cur[j] == 2)
				hasO = 1;
		}
	}

	int cur[2] = {0, 0};

	rep(i, 0, 4)
	{
		cur[0] |= board[i][i];
		cur[1] |= board[3-i][i];
	}

	rep(j, 0, 2)
	{
		if (cur[j] == 1)
			hasX = 1;
		else if (cur[j] == 2)
			hasO = 1;
	}

	if (notFinished && !hasX && !hasO)
	{
		printf("Game has not completed\n");
	}
	else if (hasX)
	{
		printf("X won\n");
	}
	else if (hasO)
	{
		printf("O won\n");
	}
	else
	{
		printf("Draw\n");
	}
}