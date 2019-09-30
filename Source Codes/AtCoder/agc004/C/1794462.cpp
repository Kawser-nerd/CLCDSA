#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <iomanip>
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
#include <iterator>
#include <bitset>
#include <ctime>
#include<unordered_set>
#include<complex>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 500 + 47;

int A[MAX][MAX];
int B[MAX][MAX];
int C[MAX][MAX];
int h, w;
string s;

void print(int A[MAX][MAX])
{
	FOR(i, 0, h)
	{
		FOR(j, 0, w)
		{
			cout << (A[i][j] ? '#' : '.');
		}

		cout << endl;
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> h >> w;
	FOR(i, 0, h)
	{
		cin >> s;
		FOR(j, 0, SZ(s))
		{
			A[i][j] = s[j] == '#';
		}
	}

	FOR(i, 0, h)
	{
		FOR(j, 0, w)
		{
			if (j == w - 1) continue;
			if (j == 0 || (i & 1) || A[i][j])
			{
				B[i][j] = 1;
			}
		}
	}

	FOR(i, 0, h)
	{
		FOR(j, 0, w)
		{
			if (j == 0) continue;
			if (j == w - 1 || (i & 1) == 0 || A[i][j])
			{
				C[i][j] = 1;
			}
		}
	}

	print(B);
	cout << endl;
	print(C);
}