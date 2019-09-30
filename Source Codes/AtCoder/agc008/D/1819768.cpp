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

const int MAX = 1000 * 1000 + 47;
struct Item
{
	int i, pos, left;
	Item(int i1, int pos1, int left1)
	{
		i = i1;
		pos = pos1;
		left = left1;
	}

	Item() {}
};

int A[MAX];
Item X[MAX];

bool cmp(Item a, Item b)
{
	return a.pos < b.pos;
}

void no()
{
	cout << "No" << endl;
	exit(0);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		int x;
		cin >> x;
		x--;
		X[i] = Item(i, x, i);
	}

	sort(X, X + n, cmp);
	FILL(A, -1);
	int p = 0;
	FOR(i, 0, n)
	{
		//cout << X[i].i << " " << X[i].left << endl;
		while (X[i].left != 0)
		{
			if (A[p] == -1)
			{
				X[i].left--;
				A[p] = X[i].i;
			}

			p++;
		}

		if (A[X[i].pos] != -1) no();
		A[X[i].pos] = X[i].i;
	}

	p = 0;
	FOR(i, 0, n * n)
	{
		while (p < n && X[p].left == n - X[p].i - 1) p++;
		if (p == n) break;

		if (A[i] == -1)
		{
			if (X[p].pos > i) no();
			A[i] = X[p].i;
			X[p].left++;
		}
	}

	//FOR(i, 0, n)
	//{
	//	FOR(k, 0, n - i - 1)
	//	{
	//		while (A[p] != -1) p++;
	//		A[p] = X[k].i;
	//	}
	//}

	cout << "Yes" << endl;
	FOR(i, 0, n * n)
	{
		cout << A[i] + 1 << " ";
	}

	cout << endl;
}