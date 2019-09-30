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
typedef long long __int1288;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 3 * 1000 + 47;
const int MAX1 = 1000 * 100 + 47;

__int1288 A[MAX1];
int P[MAX];
__int1288 L[MAX];
int sz;

map<__int1288, int> mapp;

void norm(__int1288& a)
{
	FOR(i, 0, sz)
	{
		__int1288 l = L[i] * L[i] * L[i];
		while (a % l == 0)
		{
			a /= l;
		}
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	FOR(i, 2, MAX)
	{
		if (!P[i])
		{
			L[sz++] = i;
			int j = i;
			while (j < MAX)
			{
				if (P[j] == 0) P[j] = i;
				j += i;
			}
		}
	}

	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		LL l;
		cin >> l;
		norm(l);
		mapp[l]++;
	}

	int ans = 0;
	for (auto i = mapp.begin(); i != mapp.end(); i++)
	{
		__int1288 a = i->first;
		__int1288 b = a * a;
		norm(b);
		if (a == 1 && mapp[a] != 0)
		{
			ans++;
			mapp[a] = 0;
			continue;
		}

		ans += max(mapp[a], mapp[b]);
		mapp[a] = 0;
		mapp[b] = 0;
	}

	cout << ans << endl;
}