#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<long double, long double> PDD;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 200007;
const int MAX2 = 10007;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 0;

int a[MAX];

int main()
{
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);

	int t;
	cin >> t;
	FOR(tt,0,t)
	{
		int n , k;
		cin >> n >> k;
		vector<PII> A(n);
		FOR(i,0,n)
		{
			cin >> A[i].second >> A[i].first;
		}
		sort(ALL(A));
		reverse(ALL(A));
		Int mx = -1;
		FOR(i,0,n)
		{
			Int val = 1LL * A[i].second * A[i].second + 2LL * A[i].first * A[i].second;
			vector<Int> B;
			FOR(j,0,n)
			{
				if (j == i) continue;
				B.push_back(2LL * A[j].first * A[j].second);
			}
			sort(ALL(B));
			reverse(ALL(B));
			FOR(j,0,k - 1)
			{
				val += B[j];
			}
			mx = max(mx , val);
		}

		printf("Case #%d: %.10f\n" , tt + 1 , 1.0 * mx * Pi);

	}

    return 0;
}
