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
#include<unordered_set>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const LL INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 100 * 1000 + 47;

LL A[MAX];

void no()
{
	cout << -1 << endl;
	exit(0);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	A[0] = 1;
	FOR(i, 1, n + 1) cin >> A[i];
	LL k = 2;
	if (A[n] != 2) no();

	LL a = 2;
	LL b = 2;

	RFOR(i, n + 1, 1)
	{
		b = b + A[i] - 1;
		a = ((a + A[i - 1] - 1) / A[i - 1]) * A[i - 1];
		b = (b / A[i - 1]) * A[i - 1];
		if (a > b) no();
	}

	cout << a << " " << b << endl;
}