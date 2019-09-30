//#pragma comment(linker, "/STACK:134217728")

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

char buf[1 << 20];
string S[1 << 20];
int L[1 << 20];
int R[1 << 12][8];
int gCnt;

int SolveTest(int test)
{
	scanf("%s", buf);
	int n = strlen(buf);

	int i, j, k;
	FOR(i, 0, n + 1)
		FOR(j, 0, 5)
			R[i][j] = n + 1;

	R[0][4] = 0;
	FOR(i, 0, n)
	{
		FOR(j, 0, 5)
			if(R[i][j] != n + 1)
				break;

		if(j == 5)
			continue;

		FOR(j, 0, gCnt)
			if(i + L[j] <= n)
			{
				int prev = -1;
				int first = -1;
				int cnt = 0;
				FOR(k, 0, L[j])
					if(buf[i + k] != S[j][k])
					{
						++cnt;
						if(prev == -1)
							first = min(4, k);
						else if(k - prev < 5)
							break;

						prev = k;
					}

				int last = min(4, L[j] - prev - 1);
				if(k == L[j])
				{
					if(cnt == 0)
					{
						FOR(k, 0, 5)
							if(R[i][k] != n + 1)
								R[ i + L[j] ][ min(4, k + L[j]) ] = min(R[ i + L[j] ][ min(4, k + L[j]) ], R[i][k]);
					}
					else
					{
						FOR(k, 4 - first, 5)
							if(R[i][k] != n + 1)
								R[ i + L[j] ][last] = min(R[ i + L[j] ][last], R[i][k] + cnt);
					}
				}
			}
	}

	int res = n + 1;
	FOR(i, 0, 5)
		res = min(res, R[n][i]);

	printf("Case #%d: %d\n", test + 1, res);
	return 0;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	gCnt = 0;
	int Max = 0;
	FILE* file = fopen("garbled_email_dictionary.txt", "r");
	while(fscanf(file, "%s", buf) != EOF)
	{
		S[gCnt] = buf;
		L[gCnt] = strlen(buf);
		Max = max(Max, L[gCnt]);
		++gCnt;
	}
	fclose(file);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
