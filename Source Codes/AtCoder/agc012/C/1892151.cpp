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

const int MAX = 100 + 47;
const int L = 100;
const int MOD = 1000 * 1000 * 1000 + 7;

deque<int> P;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);

	LL n;
	cin >> n;
	n++;
	int p = -1;
	RFOR(i, 40, 0)
	{
		if (n & (1LL << i))
		{
			p = i;
			break;
		}
	}

	int cnt = 0;
	//cout << "!!" << p << endl;
	RFOR(i, p, 0)
	{
		P.push_back(cnt++);
		if ((1LL << i) & n) P.push_front(cnt++);
	}

	cout << SZ(P) + 100 << endl;
	while (!P.empty())
	{
		cout << P.front() + 1 << " ";
		P.pop_front();
	}

	FOR(i, 0, 100)
	{
		cout << i + 1 << " ";
	}

	cout << endl;
}