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

const int MAX = 1000 * 100 + 47;
int A[MAX];
int n;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

bool isWin()
{
	int cnt0 = 0, cnt1 = 0;
	FOR(i, 0, n)
	{
		if (A[i] % 2) cnt1++;
		if (A[i] % 2 == 0) cnt0++;
	}

	if (cnt0 % 2) return true;
	if (cnt0 % 2 == 0 && cnt1 >= 2) return false;

	int ind = -1;
	FOR(i, 0, n)
	{
		if (A[i] == 1) continue;
		if (A[i] % 2)
		{
			ind = i;
			break;
		}
	}

	if (ind == -1) return false;
	A[ind]--;
	int g = A[0];
	FOR(i, 0, n)
	{
		g = gcd(A[i], g);
	}

	FOR(i, 0, n)
	{
		A[i] /= g;
	}

	return !isWin();
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	LL s = 0;
	FOR(i, 0, n)
	{
		cin >> A[i];
	}

	if (isWin())
	{
		cout << "First" << endl;
		return 0;
	}

	cout << "Second" << endl;
}