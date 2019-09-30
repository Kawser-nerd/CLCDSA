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

const int MAX = 2000 + 47;

int A[MAX];
int B[MAX];
int B1[MAX];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n; 
	LL x;
	cin >> n >> x;
	FOR(i, 0, n)
	{
		cin >> A[i];
		B[i] = A[i];
	}

	LL ans = LINF;
	FOR(k, 0, n)
	{
		LL summ = 0;
		FOR(i, 0, n) summ += B[i];
		ans = min(ans, k * x + summ);
		FOR(i, 0, n)
		{
			B1[i] = min(A[i], B[(i - 1 + n) % n]);
		}

		FOR(i, 0, n)
		{
			B[i] = B1[i];
		}
	}

	cout << ans << endl;
}