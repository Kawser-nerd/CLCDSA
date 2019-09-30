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

const int MAX = 5 * 100000 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;

int A[MAX];
string s;
int n;
int summ = 0;

void addOne()
{
	FOR(i, 0, n)
	{
		if (A[i] != 9)
		{
			summ++;
			A[i]++;
			break;
		}

		summ -= 9;
		A[i] = 0;
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	n = SZ(s);
	FOR(i, 0, n)
	{
		A[i] = s[n - i - 1] - '0';
	}

	int nex = 0;
	FOR(i, 0, n + 1)
	{
		int val = A[i] * 9 + nex;
		A[i] = val % 10;
		nex = val / 10;
	}

	if (A[n]) n++;
	FOR(i, 0, n)
	{
		summ += A[i];
	}

	FOR(k, 1, MAX)
	{
		FOR(i, 0, 9)
		{
			addOne();
		}

		if (summ <= 9 * k)
		{
			cout << k << endl;
			return 0;
		}
	}
}