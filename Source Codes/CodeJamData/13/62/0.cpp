#define _CRT_SECURE_NO_WARNINGS
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

#define MAX 64

int A[1 << 20];

int SolveTest(int test)
{
	int N;
	scanf("%d", &N);

	int i, j, k;
	FOR(i, 0, N)
		scanf("%d", &A[i]);

	double Min = 0, Max = 1e7;
	FOR(i, 0, MAX)
	{
		double Mid = (Max + Min)/2;

		double Min2 = 0, Max2 = 1e7;
		FOR(j, 0, MAX)
		{
			double Mid2 = (Min2 + Max2)/2;

			double left = A[0] - Mid;
			double right = A[0] + Mid;
			FOR(k, 1, N)
			{
				left += Mid2;
				right += Mid2;

				double l = A[k] - Mid;
				double r = A[k] + Mid;
				
				if(left > r)
				{
					Max2 = Mid2;
					break;
				}

				if(right < l)
				{
					Min2 = Mid2;
					break;
				}

				left = max(left, l);
				right = min(right, r);
			}

			if(k == N)
				break;
		}

		if(j == MAX)
			Min = Mid;
		else
			Max = Mid;
	}

	printf("Case #%d: %.11lf\n", test + 1, Max);
	return 0;
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

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
